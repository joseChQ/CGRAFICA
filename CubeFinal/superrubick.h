#ifndef SUPERRUBICK_H
#define SUPERRUBICK_H_H

#include <vector>
#include "cube.h"
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
struct Srubick {
	std::vector<rubic*> mrubick;
	std::vector< glm::vec3 > pos;
	int N;
	Srubick() :mrubick(27, nullptr), N(27)
	{
		for (int i = 0; i < N; ++i)
		{
			mrubick[i] = new rubic();
			mrubick[i]->Scolor();
			
		}
		pos.emplace_back(-0.2f, 0.2f, 0.2f);   //p[0][0][0]
		pos.emplace_back(-0.2f, 0.2f, 0.0f);   //p[0][0][1]
		pos.emplace_back(-0.2f, 0.2f, -0.2f);  //p[0][0][2]
		pos.emplace_back(0.0f, 0.2f, 0.2f);   //p[0][1][0]
		pos.emplace_back(0.0f, 0.2f, 0.0f);   //p[0][1][1]
		pos.emplace_back(0.0f, 0.2f, -0.2f);  //p[0][1][2]
		pos.emplace_back(0.2f, 0.2f, 0.2f);    //p[0][1][0]
		pos.emplace_back(0.2f, 0.2f, 0.0f);    //p[0][1][1]
		pos.emplace_back(0.2f, 0.2f, -0.2f);   //p[0][1][2]

		pos.emplace_back(-0.2f, 0.0f, 0.2f);   //p[1][0][0]
		pos.emplace_back(-0.2f, 0.0f, 0.0f);   //p[1][0][1]
		pos.emplace_back(-0.2f, 0.0f, -0.2f);  //p[1][0][2]
		pos.emplace_back(0.0f, 0.0f, 0.2f);    //p[1][1][0]
		pos.emplace_back(0.0f, 0.0f, 0.0f);    //p[1][1][1]
		pos.emplace_back(0.0f, 0.0f, -0.2f);   //p[1][1][2]
		pos.emplace_back(0.2f, 0.0f, 0.2f);    //p[1][1][0]
		pos.emplace_back(0.2f, 0.0f, 0.0f);    //p[1][1][1]
		pos.emplace_back(0.2f, 0.0f, -0.2f);   //p[1][1][2]

		pos.emplace_back(-0.2f, -0.2f, 0.2f);   //p[2][0][0]
		pos.emplace_back(-0.2f, -0.2f, 0.0f);   //p[2][0][1]
		pos.emplace_back(-0.2f, -0.2f, -0.2f);  //p[2][0][2]
		pos.emplace_back(0.0f, -0.2f, 0.2f);    //p[2][1][0]
		pos.emplace_back(0.0f, -0.2f, 0.0f);    //p[2][1][1]
		pos.emplace_back(0.0f, -0.2f, -0.2f);   //p[2][1][2]
		pos.emplace_back(0.2f, -0.2f, 0.2f);    //p[2][1][0]
		pos.emplace_back(0.2f, -0.2f, 0.0f);    //p[2][1][1]
		pos.emplace_back(0.2f, -0.2f, -0.2f);   //p[2][1][2]
	}
	void fun() {
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				glGenVertexArrays(1, &(mrubick[i]->cubitos[j]->VAO));
				glGenBuffers(1, &(mrubick[i]->cubitos[j]->VBO));

				glBindVertexArray((mrubick[i]->cubitos[j]->VAO));
				glBindBuffer(GL_ARRAY_BUFFER, (mrubick[i]->cubitos[j]->VBO));
				glBufferData(GL_ARRAY_BUFFER, sizeof(mrubick[i]->cubitos[j]->vertex), mrubick[i]->cubitos[j]->vertex, GL_STATIC_DRAW);

				// position attribute
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
				glEnableVertexAttribArray(0);
				// color attribute
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
				glEnableVertexAttribArray(1);
				// texture coord attribute
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
				glEnableVertexAttribArray(2);
			}
		}
	}

	void Alejar() {
		for (auto& i : pos)
		{
			i.x *= 4;
			i.y *= 4;
			i.z *= 4;
		}
	}
	void Acercar() {
		for (auto& i : pos)
		{
			i.x /= 4;
			i.y /= 4;
			i.z /= 4;
		}
	}
};
#endif