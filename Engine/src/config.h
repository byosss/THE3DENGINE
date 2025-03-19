#pragma once

#include "Scene/SceneManager.h"

#include "Scene/Components/Transform.h"
#include "Renderer/Components/Camera.h"
#include "Renderer/Components/MeshRenderer.h"

#include "Resource/Resources/Mesh.h"


void load( SceneManager& scene ) 
{
    // Définit des tableaux statiques pour garantir la durée de vie
    static float positionsData[] = { 
        0.5f,  0.5f,  0.5f, 
       -0.5f,  0.5f,  0.5f, 
       -0.5f, -0.5f,  0.5f, 
        0.5f, -0.5f,  0.5f 
    };
    static float normalsData[] = {
        0.0f, 0.0f, 1.0f, 
        0.0f, 0.0f, 1.0f, 
        0.0f, 0.0f, 1.0f, 
        0.0f, 0.0f, 1.0f 
    };
    static float uvsData[] = {
        1.0f, 1.0f, 
        0.0f, 1.0f, 
        0.0f, 0.0f, 
        1.0f, 0.0f 
    };
    static unsigned int indicesData[] = {
        0, 1, 3,
        1, 2, 3
    };

    Mesh mesh;
    mesh.positions = std::span<float>( positionsData, sizeof(positionsData) / sizeof(float) );
    mesh.normals   = std::span<float>( normalsData,   sizeof(normalsData) / sizeof(float) );
    mesh.uvs       = std::span<float>( uvsData,       sizeof(uvsData) / sizeof(float) );
    mesh.indices   = std::span<unsigned int>( indicesData, sizeof(indicesData) / sizeof(unsigned int) );


    entt::entity cube = scene.createEntity();


    entt::entity camera = scene.createEntity();
}