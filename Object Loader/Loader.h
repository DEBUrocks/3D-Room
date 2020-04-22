#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
///Namespace: OBJL
///Holds eveyrthing used for the OBJ Model Loader
namespace objl
{
///Structure: Vector3
///3D Vector that Holds Positional Data
struct Vector3
{
	///Default Constructor
	Vector3()
	{
		X = 0.0f;
		Y = 0.0f;
		Z = 0.0f;
	}
	///Variable Set Constructor
	Vector3(float X_, float Y_, float Z_)
	{
		X = X_;
		Y = Y_;
		Z = Z_;
	}
	///Positional Variables
	float X;
	float Y;
	float Z;
};
///Structure: Vertex
///Model Vertex object that holds Position
struct Vertex
{
	///Position Vector
	Vector3 Position;
};
///Structure: Mesh
///Simple Mesh Object that has Vertex and Index
struct Mesh
{
	///Default Constructor
	Mesh()
	{
	}
	///Variable Set Constructor
	Mesh(std::vector<Vertex> &_Vertices, std::vector<unsigned int> &_Indices)
	{
		Vertices = _Vertices;
		Indices = _Indices;
	}
	///Vertex List
	std::vector<Vertex> Vertices;
	///Index List
	std::vector<unsigned int> Indices;
};
///Namespace: Algorithm
///Holds all of the Algorithms needed for OBJL
namespace algorithm
{
///Split a String into a string array at a given token
inline void split(const std::string &in, std::vector<std::string> &out, std::string token)
{
	out.clear();
	std::string temp;
	for (int i = 0; i < int(in.size()); i++)
	{
		std::string test = in.substr(i, token.size());
		if (test == token)
		{
			if (!temp.empty())
			{
				out.push_back(temp);
				temp.clear();
				i += (int)token.size() - 1;
			}
			else
				out.push_back("");
		}
		else if (i + token.size() >= in.size())
		{
			temp += in.substr(i, token.size());
			out.push_back(temp);
			break;
		}
		else
			temp += in[i];
	}
}
///Get tail of string after first token and possibly following spaces
inline std::string tail(const std::string &in)
{
	size_t token_start = in.find_first_not_of(" \t");
	size_t space_start = in.find_first_of(" \t", token_start);
	size_t tail_start = in.find_first_not_of(" \t", space_start);
	size_t tail_end = in.find_last_not_of(" \t");
	if (tail_start != std::string::npos && tail_end != std::string::npos)
		return in.substr(tail_start, tail_end - tail_start + 1);
	else if (tail_start != std::string::npos)
		return in.substr(tail_start);
	return "";
}
///Get first token of string
inline std::string firstToken(const std::string &in)
{
	if (!in.empty())
	{
		size_t token_start = in.find_first_not_of(" \t");
		size_t token_end = in.find_first_of(" \t", token_start);
		if (token_start != std::string::npos && token_end != std::string::npos)
			return in.substr(token_start, token_end - token_start);
		else if (token_start != std::string::npos)
			return in.substr(token_start);
	}
	return "";
}
///Get element at given index position
template <class T>
inline const T &getElement(const std::vector<T> &elements, std::string &index)
{
	int idx = std::stoi(index);
	if (idx < 0)
		idx = int(elements.size()) + idx;
	else
		idx--;
	return elements[idx];
}
} // namespace algorithm
///Class: Loader
///The OBJ Model Loader
class Loader
{
public:
	///Default Constructor
	Loader()
	{
	}
	~Loader()
	{
		LoadedMeshes.clear();
	}
	///Load a file into the loader
	///If file is loaded return true
	///If the file is not found return false
	bool LoadFile(std::string Path)
	{
		if (Path.substr(Path.size() - 4, 4) != ".obj")//If the file is not an .obj file return false
			return false;
		std::ifstream file(Path);
		if (!file.is_open())
			return false;
		LoadedMeshes.clear();
		LoadedVertices.clear();
		LoadedIndices.clear();
		std::vector<Vector3> Positions;
		std::vector<Vertex> Vertices;
		std::vector<unsigned int> Indices;
		bool listening = false;
		Mesh tempMesh;
		std::string curline;
		while (std::getline(file, curline))
		{
			if (algorithm::firstToken(curline) == "o" || algorithm::firstToken(curline) == "g" || curline[0] == 'g')// Generate a Mesh Object
			{
				if (!listening)
					listening = true;
				else
				{
					if (!Indices.empty() && !Vertices.empty())// Generate the mesh to put into the array
					{
						tempMesh = Mesh(Vertices, Indices);// Create Mesh
						LoadedMeshes.push_back(tempMesh);// Insert Mesh
						Vertices.clear();// Cleanup
						Indices.clear();// Cleanup
					}
				}
			}
			if (algorithm::firstToken(curline) == "v")// Generate a Vertex Position
			{
				std::vector<std::string> spos;
				Vector3 vpos;
				algorithm::split(algorithm::tail(curline), spos, " ");
				vpos.X = std::stof(spos[0]);
				vpos.Y = std::stof(spos[1]);
				vpos.Z = std::stof(spos[2]);
				Positions.push_back(vpos);
			}
			if (algorithm::firstToken(curline) == "f")// Generate a Face (vertices & indices)
			{
				std::vector<Vertex> vVerts;// Generate the vertices
				GenVerticesFromRawOBJ(vVerts, Positions, curline);
				for (int i = 0; i < int(vVerts.size()); i++)// Add Vertices
				{
					Vertices.push_back(vVerts[i]);
					LoadedVertices.push_back(vVerts[i]);
				}
				std::vector<unsigned int> iIndices;
				VertexTriangluation(iIndices, vVerts);
				for (int i = 0; i < int(iIndices.size()); i++)// Add Indices
				{
					unsigned int indnum = (unsigned int)((Vertices.size()) - vVerts.size()) + iIndices[i];
					Indices.push_back(indnum);
					indnum = (unsigned int)((LoadedVertices.size()) - vVerts.size()) + iIndices[i];
					LoadedIndices.push_back(indnum);
				}
			}
		}
		if (!Indices.empty() && !Vertices.empty())//Last mesh
		{
			tempMesh = Mesh(Vertices, Indices);// Create Mesh
			LoadedMeshes.push_back(tempMesh);// Insert Mesh
		}
		file.close();
		if (LoadedMeshes.empty() && LoadedVertices.empty() && LoadedIndices.empty())
			return false;
		else
			return true;
	}
	std::vector<Mesh> LoadedMeshes;// Loaded Mesh Objects
	std::vector<Vertex> LoadedVertices;// Loaded Vertex Objects
	std::vector<unsigned int> LoadedIndices;// Loaded Index Positions
private:
	///Generate vertices from a list of positions
	void GenVerticesFromRawOBJ(std::vector<Vertex> &oVerts, const std::vector<Vector3> &iPositions, std::string icurline)
	{
		std::vector<std::string> sface, svert;
		Vertex vVert;
		algorithm::split(algorithm::tail(icurline), sface, " ");
		for (int i = 0; i < int(sface.size()); i++)// For every given vertex do this
		{
			algorithm::split(sface[i], svert, "/");
			vVert.Position = algorithm::getElement(iPositions, svert[0]);
			oVerts.push_back(vVert);
		}
	}
	///Triangulate a list of vertices into a face by printing
	///indicies corresponding with triangles within it
	void VertexTriangluation(std::vector<unsigned int> &oIndices, const std::vector<Vertex> &iVerts)
	{
		if (iVerts.size() < 3)//If 2 or less vertices triangle cant be made so exit
			return;
		if (iVerts.size() == 3)//If it is already trianfulated, no need to do anything
		{
			oIndices.push_back(0);
			oIndices.push_back(1);
			oIndices.push_back(2);
			return;
		}
	}
};
} // namespace objl

