#include <iostream>
#include <fstream>
#include "Loader.h"
int main(int argc, char *argv[])
{
	objl::Loader Loader;							  // Initialize Loader (next line loads the obj)
	bool loadout = Loader.LoadFile("WineBottle.obj"); //Change this Parameter to Use another object as input
	// If file got loaded then loader will be true
	if (loadout)
	{
		std::ofstream file("WineBottle.txt"); //Change this Parameter for changing the name of the output file
		// Load The mesh to our current mesh
		objl::Mesh curMesh = Loader.LoadedMeshes[0];
		// Go through each Vertex and Print the vertex functions
		for (int j = 0; j < curMesh.Vertices.size(); j++)
		{
			file << "glVertex3f(" << curMesh.Vertices[j].Position.X << "," << curMesh.Vertices[j].Position.Y << "," << curMesh.Vertices[j].Position.Z << ");\n";
		}
		file.close(); // Close File
	}
	// If some error Happens
	else
	{
		std::ofstream file("error.txt");
		file << "Failed to Load File\n";
		file.close();
	}
	return 0;
}
