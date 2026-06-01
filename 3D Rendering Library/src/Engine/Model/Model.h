#pragma once

#include <glad/glad.h> 

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

#include <stb_image.h>

#include "../Material/Shader.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define MAX_BONE_INFLUENCE 4

struct Vertex
{
// position
  glm::vec3 Position;
  // normal
  glm::vec3 Normal;
  // texCoords
  glm::vec2 TexCoords;
  // tangent
  glm::vec3 Tangent;
  // bitangent
  glm::vec3 Bitangent;
  //bone indexes which will influence this vertex
  int m_BoneIDs[MAX_BONE_INFLUENCE];
  //weights from each bone
  float m_Weights[MAX_BONE_INFLUENCE];
};

struct ModelTexture
{
  unsigned int id;
  string type;
  string path;
};

class ModelMesh
{
public:
    // ModelMesh Data
  vector<Vertex>       vertices;
  vector<unsigned int> indices;
  vector<ModelTexture>      ModelTextures;
  unsigned int VAO;

  // constructor
  ModelMesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<ModelTexture> ModelTextures)
  {
    this->vertices = vertices;
    this->indices = indices;
    this->ModelTextures = ModelTextures;

    // now that we have all the required data, set the vertex buffers and its attribute pointers.
    setupModelMesh();
  }

private:
    // render data 
  unsigned int VBO, EBO;

  // initializes all the buffer objects/arrays
  void setupModelMesh()
  {
      // create buffers/arrays
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    // load data into vertex buffers
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // A great thing about structs is that their memory layout is sequential for all its items.
    // The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
    // again translates to 3/2 floats which translates to a byte array.
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    // set the vertex attribute pointers
    // vertex Positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);
    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, Normal));
    // vertex ModelTexture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, TexCoords));
    // vertex tangent
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, Tangent));
    // vertex bitangent
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, Bitangent));
// ids
    glEnableVertexAttribArray(5);
    glVertexAttribIPointer(5, 4, GL_INT, sizeof(Vertex), (void *)offsetof(Vertex, m_BoneIDs));

    // weights
    glEnableVertexAttribArray(6);
    glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, m_Weights));
    glBindVertexArray(0);
  }
};


class Model
{
public:
    // model data 
  vector<ModelTexture> textures_loaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
  vector<ModelMesh>    meshes;
  string directory;
  bool gammaCorrection;

  Model() = default;

  // constructor, expects a filepath to a 3D model.
  Model(string const &path, bool gamma = false) : gammaCorrection(gamma)
  {
    loadModel(path);
  }

  void create(string const &path, bool gamma = false)
  {
    gammaCorrection = gamma;
    loadModel(path);
  }

private:

  unsigned int TextureFromFile(const char *path, const string &directory, bool gamma);

  // loads a model with supported ASSIMP extensions from file and stores the resulting meshes in the meshes vector.
  void loadModel(string const &path);

  // processes a node in a recursive fashion. Processes each individual mesh located at the node and repeats this process on its children nodes (if any).
  void processNode(aiNode *node, const aiScene *scene);

  ModelMesh processMesh(aiMesh *mesh, const aiScene *scene);

  // checks all material textures of a given type and loads the textures if they're not loaded yet.
  // the required info is returned as a Texture struct.
  vector<ModelTexture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
};

