#pragma once

#include <iostream>
#include <string>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Resource.h"
#include "Mesh.h"

class Model : public Resource {
public:
    explicit Model(const std::string& path) {
        // Load model from file
        Assimp::Importer importer;

        const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

        if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
            std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
            return;
        }

        // Process ASSIMP's root node recursively
        processNode(scene->mRootNode, scene);
    }
    ~Model() {
        // Release model data
        // ...
        std::cout << "Destruction du model 3d" << std::endl;
    }

private:
    void processNode(aiNode* node, const aiScene* scene) {
        // Process each mesh located at the current node
        for (unsigned int i = 0; i < node->mNumMeshes; i++) {
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
            m_meshes.push_back(processMesh(mesh));
        }

        // Process each child node
        for (unsigned int i = 0; i < node->mNumChildren; i++) {
            processNode(node->mChildren[i], scene);
        }
    }

    Mesh processMesh(aiMesh* mesh) {
        
        // Mesh mesh(mesh->mVertices, mesh->mNumVertices, 

        
    }

    std::vector<Mesh> m_meshes;
};