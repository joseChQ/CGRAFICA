#ifndef CUBE1_H
#define CUBE1_H
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <time.h>
#include <random>
#include "Cube.hpp"
#include "Cross.hpp"
#include "Corners.hpp"
#include "Edges.hpp"
#include "OLL.hpp"
#include "PLL.hpp"
#include <string>
struct Cube1
{
	float vertex[288];
	unsigned int VAO;
	unsigned int VBO;
	float x, y, z;
	int Animation1[2];
	int Animation2[2];
	int Animation3[2];
	int t;
	int plusX;
	int id_;
	int plusZ;
	Cube1(int id): t(1), plusX(0), plusZ(0),id_(id)
	{
		Animation1[0] = Animation1[1] = 0; 
		Animation2[0] = Animation2[1] = 0;
		Animation3[0] = Animation3[1] = 0;
		float tmp[] = {

			//cara derecha
			
			 0.1f,  0.1f,  0.1f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			 0.1f,  0.1f, -0.1f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			 0.1f, -0.1f, -0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			 0.1f, -0.1f, -0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			 0.1f, -0.1f,  0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			 0.1f,  0.1f,  0.1f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			//cara  frente
			
			
			-0.1f, -0.1f,  0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			0.1f, -0.1f,  0.1f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			0.1f,  0.1f,  0.1f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			0.1f,  0.1f,  0.1f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			-0.1f,  0.1f,  0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			-0.1f, -0.1f,  0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			
			//cara atraz
			
			-0.1f, -0.1f, -0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			 0.1f, -0.1f, -0.1f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			 0.1f,  0.1f, -0.1f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			 0.1f,  0.1f, -0.1f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			-0.1f,  0.1f, -0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			-0.1f, -0.1f, -0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,

			//cara abajo
			
			-0.1f, -0.1f, -0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		  	 0.1f, -0.1f, -0.1f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		 	 0.1f, -0.1f,  0.1f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			 0.1f, -0.1f,  0.1f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			-0.1f, -0.1f,  0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			-0.1f, -0.1f, -0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			//cara arriva
			
			
			-0.1f,  0.1f, -0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			 0.1f,  0.1f, -0.1f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			 0.1f,  0.1f,  0.1f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			 0.1f,  0.1f,  0.1f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			-0.1f,  0.1f,  0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			-0.1f,  0.1f, -0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			//cara izquierda
			
			-0.1f,  0.1f,  0.1f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			-0.1f,  0.1f, -0.1f,  0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			-0.1f, -0.1f, -0.1f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			-0.1f, -0.1f, -0.1f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			-0.1f, -0.1f,  0.1f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			-0.1f,  0.1f,  0.1f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		};
		for(int i = 0; i < 288; ++i)
		{
			vertex[i] = tmp[i]/2;
		}
		
		x = y = z = 0.f;
	}

	void rotateX(glm::mat4 &model,bool &check,int i)
	{
		
		if (Animation1[0]) {
			model = glm::rotate(model, glm::radians(0.0625f * t ), glm::vec3(1.0f, 0.0f, 0.0f));
			t = t + 1;
			if (t >= 1440)
			{
				Animation1[0] = false;
				t = 1;
				check = true;
			}
		}
		if (Animation1[1]) {
			model = glm::rotate(model, glm::radians(-0.0625f * t), glm::vec3(1.0f, 0.0f, 0.0f));
			t = t + 1;
			if (t >= 1440)
			{
				Animation1[1] = false;
				t = 1;
				check = true;
			}
		}
	}

	void rotateZ(glm::mat4& model,bool &check,int i)
	{

		if (Animation2[0]) {
			model = glm::rotate(model, glm::radians(-0.0625f * t ), glm::vec3(0.0f, 0.0f, 1.0f));
			t = t + 1;
			if (t >= 1440)
			{
				Animation2[0] = false;
				t = 1;
				check = true;
			}
		}
		if (Animation2[1]) {
			model = glm::rotate(model, glm::radians(0.0625f * t), glm::vec3(0.0f, 0.0f, 1.0f));
			t = t + 1;
			if (t >= 1440)
			{
				Animation2[1] = false;
				t = 1;
				check = true;
			}
		}
	}
	void rotateY(glm::mat4& model, bool& check, int i)
	{

		if (Animation3[0]) {
			model = glm::rotate(model, glm::radians(-0.0625f * t), glm::vec3(0.0f, 1.0f, 0.0f));
			t = t + 1;
			if (t >= 1440)
			{
				Animation3[0] = false;
				t = 1;
				check = true;
			}
		}
		if (Animation3[1]) {
			model = glm::rotate(model, glm::radians(0.0625f * t), glm::vec3(0.0f, 1.0f, 0.0f));
			t = t + 1;
			if (t >= 1440)
			{
				Animation3[1] = false;
				t = 1;
				check = true;
			}
		}
	}
};
struct rubic
{
	std::vector< Cube1* > cubitos;
	std::vector< glm::vec3 > pos;
	std::vector<std::string> Rmove;
	std::vector<std::string> move;
	int ix;
	int FinalZ1[2];
	int FinalZ2[2];
	int FinalZ3[2];
	int FinalX1[2];
	int FinalX2[2];
	int FinalX3[2];
	int FinalY1[2];
	int FinalY3[2];
	float PI;
	rubic() :cubitos(27, nullptr), ix(0)
	{
		move = std::vector<std::string>({"R","L","U","D","F","B","R'","L'","U'","D'","F'","B'"});
		FinalZ1[0] = FinalZ1[0] = 0;
		FinalZ2[0] = FinalZ2[0] = 0;
		FinalZ3[0] = FinalZ3[0] = 0;
		FinalX1[0] = FinalX1[0] = 0;
		FinalX2[0] = FinalX2[0] = 0;
		FinalX3[0] = FinalX3[0] = 0;
		FinalY1[0] = FinalY1[0] = 0;
		FinalY3[0] = FinalY3[0] = 0;
		for (int i = 0; i < 27; ++i)
		{
			cubitos[i] = new Cube1(i);
		}
		PI = 3.1415926535897;
		pos.emplace_back(-0.2f, 0.2f, 0.2f);   //p[0][0][0]
		pos.emplace_back(-0.2f, 0.2f, 0.0f);   //p[0][0][1]
		pos.emplace_back(-0.2f, 0.2f, -0.2f);  //p[0][0][2]
		pos.emplace_back( 0.0f, 0.2f, 0.2f);   //p[0][1][0]
		pos.emplace_back( 0.0f, 0.2f, 0.0f);   //p[0][1][1]
		pos.emplace_back( 0.0f, 0.2f, -0.2f);  //p[0][1][2]
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
		for (auto &i : pos)
		{
			i.x /= 2;
			i.y /= 2;
			i.z /= 2;
		}
		
	}
	void desordenar() {
		srand(time(NULL));
		if (Rmove.size() == 0) {
			for (int i = 0; i < 10; ++i)
			{
				Rmove.push_back((move[rand() % 12]));
			}
		}
	}
	std::string movesPP()
	{
		std::string ans = "";
		for (std::string i : Rmove)
		{
			ans += (i + " ");
		}
		return ans;
	}
	void startD() {
		if (Rmove.size()&&ix< Rmove.size())
		{
			if (Rmove[ix] == "L")
			{
				rotateX1(0);
			}
			else if (Rmove[ix] == "L'")
			{
				rotateX1(1);
			}
			else if (Rmove[ix] == "R")
			{
				rotateX3(1);
			}
			else if (Rmove[ix] == "R'")
			{
				rotateX3(0);
			}
			else if (Rmove[ix] == "F")
			{
				rotateZ1(0);
			}
			else if (Rmove[ix] == "F'")
			{
				rotateZ1(1);
			}
			else if (Rmove[ix] == "B")
			{
				rotateZ3(1);
			}
			else if (Rmove[ix] == "B'")
			{
				rotateZ3(0);
			}
			else if (Rmove[ix] == "U")
			{
				rotateY1(0);
			}
			else if (Rmove[ix] == "U'")
			{
				rotateY1(1);
			}
			else if (Rmove[ix] == "D")
			{
				rotateY3(1);
			}
			else if (Rmove[ix] == "D'")
			{
				rotateY3(0);
			}
		}
	}
	void funcionResolver() {
		
		Cube myCube(false);
		std::string moves = movesPP();
		std::string scramble = format(moves);
		myCube.moves(scramble);
		myCube._moves = "";
	//	cout << "Step 1: Solve Cross\n";
		Cross::solveCross(myCube);
		myCube.movesStep[0] = myCube._moves;
		myCube.n_movesStep[0] = myCube.n_moves;
		myCube._moves = "";
		myCube.n_moves = 0;
		//cout << "Number of movements: " << myCube.n_movesStep[0] << endl;
		//cout << "Moves: " << myCube.movesStep[0] << endl << endl;

	//	cout << "Step 2: Solve Corners\n";
		Corners::solveCorners(myCube);

		myCube.movesStep[1] = myCube._moves;
		myCube.n_movesStep[1] = myCube.n_moves;
		myCube._moves = "";
		myCube.n_moves = 0;
		//cout << "Number of movements: " << myCube.n_movesStep[1] << endl;
		//cout << "Moves: " << myCube.movesStep[1] << endl << endl;

	//	cout << "Step 3: Solve Edges\n";
		Edges::solveEdges(myCube);

		myCube.movesStep[2] = myCube._moves;
		myCube.n_movesStep[2] = myCube.n_moves;
		myCube._moves = "";
		myCube.n_moves = 0;
		//cout << "Number of movements: " << myCube.n_movesStep[2] << endl;
		//cout << "Moves: " << myCube.movesStep[2] << endl << endl;


	//	cout << "Step 4: Solve OLL\n";
		OLL::solveOLL(myCube);
		myCube.movesStep[3] = myCube._moves;
		myCube.n_movesStep[3] = myCube.n_moves;
		myCube._moves = "";
		myCube.n_moves = 0;
		//cout << "Number of movements: " << myCube.n_movesStep[3] << endl;
		//cout << "Moves: " << myCube.movesStep[3] << endl << endl;


	//	cout << "Step 5: Solve PLL\n";
		PLL::solvePLL(myCube);
		myCube.movesStep[4] = myCube._moves;
		myCube.n_movesStep[4] = myCube.n_moves;
		myCube._moves = "";
		myCube.n_moves = 0;
		//cout << "Number of movements: " << myCube.n_movesStep[4] << endl;
		//cout << "Moves: " << myCube.movesStep[4] << endl<<endl;

		//cout << "End of solution " << endl;
		//cout <<"Total moves: "<< myCube.n_movesStep[0] + myCube.n_movesStep[1] + myCube.n_movesStep[2] + myCube.n_movesStep[3]+ myCube.n_movesStep[4] << endl;
		std::string ans = "";
		ans= myCube.movesStep[0] + myCube.movesStep[1] + myCube.movesStep[2] + myCube.movesStep[3] + myCube.movesStep[4];
		ans.push_back(' ');
		Rmove.clear();
		ix = 0;
	//	std::cout << "GGGGGGGGGGGGGGGGG" << std::endl;
		for (int i = 0; i < ans.size(); ++i)
		{
			if (ans[i] != '\n' && ans[i] != ' ')
			{
				std::string x;
				x.push_back(ans[i]);
				if(ans[i + 1]!='\n' &&ans[i + 1]!=' ' && ans[i + 1]!='2')
				{
					x.push_back(ans[i + 1]);
					
				}
				Rmove.push_back(x);
			//	std::cout << x << std::endl;
				if (ans[i + 1] == '2') {
					Rmove.push_back(x);
				//	std::cout << x << std::endl;
				}	
				i++;
				//std::cout << x << std::endl;
			}
		}
	//	std::cout << ":::::::::::::" << std::endl;
	//	std::cout << ans << std::endl;
		
	}
	void rotateX1(int x)
	{
		FinalX1[x] = 1;
		for (int i = 0; i < 27; i += 9)
		{
			cubitos[i]->Animation1[x] = true;
			cubitos[i+1]->Animation1[x] = true;
			cubitos[i+2]->Animation1[x] = true;
		}
	}
	void rotateX2(int x)
	{
		FinalX2[x] = 1;
		for (int i = 3; i < 27; i += 9)
		{
			cubitos[i]->Animation1[x] = true;
			cubitos[i + 1]->Animation1[x] = true;
			cubitos[i + 2]->Animation1[x] = true;
		}
	}
	void rotateX3(int x)
	{
		FinalX3[x] = 1;
		for (int i = 6; i < 27; i += 9)
		{
			cubitos[i]->Animation1[x] = true;
			cubitos[i + 1]->Animation1[x] = true;
			cubitos[i + 2]->Animation1[x] = true;
		}
	}
	
	void rotateVertexX1(float dr)
	{

		for (int i = 0; i < 27; i += 9)
		{
			for (int j = 0; j < 288; j+=8) {
				float y1 = cubitos[i ]->vertex[j + 1];
				float z1 = cubitos[i ]->vertex[j + 2];
				cubitos[i ]->vertex[j + 1] = y1 * cos(dr * PI / 180) - z1 * sin(dr * PI / 180);
				cubitos[i ]->vertex[j + 2] = y1 * sin(dr * PI / 180) + z1 * cos(dr * PI / 180);
			}

			for (int j = 0; j < 288; j += 8) {
				float y1 = cubitos[i + 1]->vertex[j + 1];
				float z1 = cubitos[i + 1]->vertex[j + 2];
				cubitos[i + 1]->vertex[j + 1] = y1 * cos(dr * PI / 180) - z1 * sin(dr * PI / 180);
				cubitos[i + 1]->vertex[j + 2] = y1 * sin(dr * PI / 180) + z1 * cos(dr * PI / 180);
			}

			for (int j = 0; j < 288; j += 8) {
				float y1 = cubitos[i + 2]->vertex[j + 1];
				float z1 = cubitos[i + 2]->vertex[j + 2];
				cubitos[i + 2]->vertex[j + 1 ] = y1 * cos(dr * PI / 180) - z1 * sin(dr * PI / 180);
				cubitos[i + 2]->vertex[j + 2] = y1 * sin(dr * PI / 180) + z1 * cos(dr * PI / 180);
			}
		}
	}
	void rotateVertexX2(float dr)
	{

		for (int i = 3; i < 27; i += 9)
		{
			for (int j = 0; j < 288; j += 8) {
				float y1 = cubitos[i]->vertex[j + 1];
				float z1 = cubitos[i]->vertex[j + 2];
				cubitos[i]->vertex[j + 1] = y1 * cos(dr * PI / 180) - z1 * sin(dr * PI / 180);
				cubitos[i]->vertex[j + 2] = y1 * sin(dr * PI / 180) + z1 * cos(dr * PI / 180);
			}

			for (int j = 0; j < 288; j += 8) {
				float y1 = cubitos[i + 1]->vertex[j + 1];
				float z1 = cubitos[i + 1]->vertex[j + 2];
				cubitos[i + 1]->vertex[j + 1] = y1 * cos(dr * PI / 180) - z1 * sin(dr * PI / 180);
				cubitos[i + 1]->vertex[j + 2] = y1 * sin(dr * PI / 180) + z1 * cos(dr * PI / 180);
			}

			for (int j = 0; j < 288; j += 8) {
				float y1 = cubitos[i + 2]->vertex[j + 1];
				float z1 = cubitos[i + 2]->vertex[j + 2];
				cubitos[i + 2]->vertex[j + 1] = y1 * cos(dr * PI / 180) - z1 * sin(dr * PI / 180);
				cubitos[i + 2]->vertex[j + 2] = y1 * sin(dr * PI / 180) + z1 * cos(dr * PI / 180);
			}
		}
	}
	void rotateVertexX3(float dr)
	{

		for (int i = 6; i < 27; i += 9)
		{
			for (int j = 0; j < 288; j += 8) {
				float y1 = cubitos[i]->vertex[j + 1];
				float z1 = cubitos[i]->vertex[j + 2];
				cubitos[i]->vertex[j + 1] = y1 * cos(dr * PI / 180) - z1 * sin(dr * PI / 180);
				cubitos[i]->vertex[j + 2] = y1 * sin(dr * PI / 180) + z1 * cos(dr * PI / 180);
			}

			for (int j = 0; j < 288; j += 8) {
				float y1 = cubitos[i + 1]->vertex[j + 1];
				float z1 = cubitos[i + 1]->vertex[j + 2];
				cubitos[i + 1]->vertex[j + 1] = y1 * cos(dr * PI / 180) - z1 * sin(dr * PI / 180);
				cubitos[i + 1]->vertex[j + 2] = y1 * sin(dr * PI / 180) + z1 * cos(dr * PI / 180);
			}

			for (int j = 0; j < 288; j += 8) {
				float y1 = cubitos[i + 2]->vertex[j + 1];
				float z1 = cubitos[i + 2]->vertex[j + 2];
				cubitos[i + 2]->vertex[j + 1] = y1 * cos(dr * PI / 180) - z1 * sin(dr * PI / 180);
				cubitos[i + 2]->vertex[j + 2] = y1 * sin(dr * PI / 180) + z1 * cos(dr * PI / 180);
			}
		}
	}
	
	void rotateZ1(int x)
	{
		FinalZ1[x] = 1;
		for (int i = 0; i < 27; i += 9)
		{
			cubitos[i]->Animation2[x] = true;
			cubitos[i + 3]->Animation2[x] = true;
			cubitos[i + 6]->Animation2[x] = true;
		}
	}
	void rotateZ2(int x)
	{
		FinalZ2[x] = 1;
		for (int i = 0; i < 27; i += 9)
		{
			cubitos[i + 1]->Animation2[x] = true;
			cubitos[i + 3 + 1]->Animation2[x] = true;
			cubitos[i + 6 + 1]->Animation2[x] = true;
		}
	}
	void rotateZ3(int x)
	{
		FinalZ3[x] = 1;
		for (int i = 0; i < 27; i += 9)
		{
			cubitos[i + 2 ]->Animation2[x] = true;
			cubitos[i + 3 + 2]->Animation2[x] = true;
			cubitos[i + 6 + 2]->Animation2[x] = true;
		}
	}
	void rotateVertexZ1(float dr)
	{

		for (int i = 0; i < 27; i += 9)
		{

			for (int j = 0; j < 288; j += 8) {
				float x1 = cubitos[i ]->vertex[j];
				float y1 = cubitos[i]->vertex[j + 1];
				cubitos[i]->vertex[j] = x1 * cos(dr * PI / 180) - y1 * sin(dr * PI / 180);
				cubitos[i]->vertex[j + 1] = x1 * sin(dr * PI / 180) + y1 * cos(dr * PI / 180);
			}
			for (int j = 0; j < 288; j += 8) {
				float x1 = cubitos[i + 3]->vertex[j];
				float y1 = cubitos[i + 3]->vertex[j + 1];
				cubitos[i + 3]->vertex[j] = x1 * cos(dr * PI / 180) - y1 * sin(dr * PI / 180);
				cubitos[i + 3]->vertex[j + 1] = x1 * sin(dr * PI / 180) + y1 * cos(dr * PI / 180);
			}
			for (int j = 0; j < 288; j += 8) {
				float x1 = cubitos[i + 6]->vertex[j];
				float y1 = cubitos[i + 6]->vertex[j + 1];
				cubitos[i + 6]->vertex[j] = x1 * cos(dr * PI / 180) - y1 * sin(dr * PI / 180);
				cubitos[i + 6]->vertex[j + 1] = x1 * sin(dr * PI / 180) + y1 * cos(dr * PI / 180);
			}
		}
	}
	void rotateVertexZ2(float dr)
	{

		for (int i = 0; i < 27; i += 9)
		{
			
			for (int j = 0; j < 288; j += 8) {
				float x1 = cubitos[i + 1]->vertex[j];
				float y1 = cubitos[i + 1]->vertex[j + 1];
				cubitos[i + 1]->vertex[j] = x1 * cos(dr * PI / 180) - y1 * sin(dr * PI / 180);
				cubitos[i + 1]->vertex[j + 1] = x1 * sin(dr * PI / 180) + y1 * cos(dr * PI / 180);
			}
			for (int j = 0; j < 288; j += 8) {
				float x1 = cubitos[i + 4]->vertex[j];
				float y1 = cubitos[i + 4]->vertex[j + 1];
				cubitos[i + 4]->vertex[j] = x1 * cos(dr * PI / 180) - y1 * sin(dr * PI / 180);
				cubitos[i + 4]->vertex[j + 1] = x1 * sin(dr * PI / 180) + y1 * cos(dr * PI / 180);
			}
			for (int j = 0; j < 288; j += 8) {
				float x1 = cubitos[i + 7]->vertex[j];
				float y1 = cubitos[i + 7]->vertex[j + 1];
				cubitos[i + 7]->vertex[j] = x1 * cos(dr * PI / 180) - y1 * sin(dr * PI / 180);
				cubitos[i + 7]->vertex[j + 1] = x1 * sin(dr * PI / 180) + y1 * cos(dr * PI / 180);
			}
		}
	}
	void rotateVertexZ3(float dr)
	{
		
		for (int i = 0; i < 27; i += 9)
		{
			for (int j = 0; j < 288; j += 8) {
				float x1 = cubitos[i + 2]->vertex[j ];
				float y1 = cubitos[i + 2]->vertex[j + 1];
				cubitos[i + 2]->vertex[j ] = x1 * cos(dr * PI / 180) - y1 * sin(dr * PI / 180);
				cubitos[i + 2]->vertex[j + 1] = x1 * sin(dr * PI / 180) + y1 * cos(dr * PI / 180);
			}
			for (int j = 0; j < 288; j += 8) {
				float x1 = cubitos[i + 5]->vertex[j];
				float y1 = cubitos[i + 5]->vertex[j + 1];
				cubitos[i + 5]->vertex[j] = x1 * cos(dr * PI / 180) - y1 * sin(dr * PI / 180);
				cubitos[i + 5]->vertex[j + 1] = x1 * sin(dr * PI / 180) + y1 * cos(dr * PI / 180);
			}
			for (int j = 0; j < 288; j += 8) {
				float x1 = cubitos[i + 8]->vertex[j];
				float y1 = cubitos[i + 8]->vertex[j + 1];
				cubitos[i + 8]->vertex[j] = x1 * cos(dr * PI / 180) - y1 * sin(dr * PI / 180);
				cubitos[i + 8]->vertex[j + 1] = x1 * sin(dr * PI / 180) + y1 * cos(dr * PI / 180);
			}
		}
	}
	/////////////ROTATEY
	void rotateY1(int x)
	{
		FinalY1[x] = 1;
		for (int i = 0; i < 9; ++i)
		{
			cubitos[i]->Animation3[x] = true;
		}
	}
	void rotateY3(int x)
	{
		FinalY3[x] = 1;
		for (int i = 18; i < 27; i++)
		{
			cubitos[i]->Animation3[x] = true;
		}
	}
	void rotateVertexY1(float dr) {
		for (int i = 0; i < 9; ++i)
		{
			//cubitos[i]->Animation3[x] = true;
			for (int j = 0; j < 288; j += 8) {
				float x1 = cubitos[i]->vertex[j];
				float z1 = cubitos[i]->vertex[j + 2];
				cubitos[i]->vertex[j] = x1 * cos(dr * PI / 180) + z1 * sin(dr * PI / 180);
				cubitos[i]->vertex[j + 2] = x1 * sin(dr * PI / 180)*-1.F + z1 * cos(dr * PI / 180);
			}
		}
	}
	void rotateVertexY3(float dr) {
		for (int i = 18; i < 27; ++i)
		{
			//cubitos[i]->Animation3[x] = true;
			for (int j = 0; j < 288; j += 8) {
				float x1 = cubitos[i]->vertex[j];
				float z1 = cubitos[i]->vertex[j + 2];
				cubitos[i]->vertex[j] = x1 * cos(dr * PI / 180) + z1 * sin(dr * PI / 180);
				cubitos[i]->vertex[j + 2] = x1 * sin(dr * PI / 180) * -1.F + z1 * cos(dr * PI / 180);
			}
		}
	}
	void Scolor()
	{
		
		//###########CARA FRENTE###########
		int tmp = 0;
		for (int i = 0; i < 25; i += 3) {

			if (i <= 6) {
				////////////y//////////////
				cubitos[i]->vertex[48 + 7] = 0.6f; //p1
				cubitos[i]->vertex[56 + 7] = 0.6f; //p2
				cubitos[i]->vertex[64 + 7] = 1.0f; //p3
				cubitos[i]->vertex[72 + 7] = 1.0f; //p4
				cubitos[i]->vertex[80 + 7] = 1.0f; //p5
				cubitos[i]->vertex[88 + 7] = 0.6f; //p6
			}
			else if (i>6&&i<=15) {
				/////////y//////////////
				cubitos[i]->vertex[48 + 7] = 0.3f; //p1
				cubitos[i]->vertex[56 + 7] = 0.3f; //p2
				cubitos[i]->vertex[64 + 7] = 0.6f; //p3
				cubitos[i]->vertex[72 + 7] = 0.6f; //p4
				cubitos[i]->vertex[80 + 7] = 0.6f; //p5
				cubitos[i]->vertex[88 + 7] = 0.3f; //p6
		
			}
			else if (i > 15)
			{
				cubitos[i]->vertex[48 + 7] = 0.0f; //p1
				cubitos[i]->vertex[56 + 7] = 0.0f; //p2
				cubitos[i]->vertex[64 + 7] = 0.3f; //p3
				cubitos[i]->vertex[72 + 7] = 0.3f; //p4
				cubitos[i]->vertex[80 + 7] = 0.3f; //p5
				cubitos[i]->vertex[88 + 7] = 0.0f; //p6
			}

			/////////////////x//////
			cubitos[i]->vertex[48 + 6] = 0.0f + float(tmp) / 10; //p1
			cubitos[i]->vertex[56 + 6] = 0.3f + float(tmp) / 10; //p2
			cubitos[i]->vertex[64 + 6] = 0.3f + float(tmp) / 10; //p3
			cubitos[i]->vertex[72 + 6] = 0.3f + float(tmp) / 10; //p4
			if (tmp == 6)
			{
				cubitos[i]->vertex[56 + 6] = 1.0f;
				cubitos[i]->vertex[64 + 6] = 1.0f;
				cubitos[i]->vertex[72 + 6] = 1.0f;
			}
			cubitos[i]->vertex[80 + 6] = 0.0f + float(tmp) / 10; //p5
			cubitos[i]->vertex[88 + 6] = 0.0f + float(tmp) / 10; //p6

			for (int j = 48; j < 97; j += 8)
			{
				cubitos[i]->vertex[j + 5] = 0.9f;
			}
			tmp += 3;
			tmp %= 9;
		}
		//###############################

		//##########CARA ARRIVA###########
		for (int i = 0; i < 9; i++) {

			if (i < 3) {
				////////////y//////////////
				cubitos[i]->vertex[192 + 6] = 0.0f; //p1
				cubitos[i]->vertex[200 + 6] = 0.3f; //p2
				cubitos[i]->vertex[208 + 6] = 0.3f; //p3
				cubitos[i]->vertex[216 + 6] = 0.3f; //p4
				cubitos[i]->vertex[224 + 6] = 0.0f; //p5
				cubitos[i]->vertex[232 + 6] = 0.0f; //p6
			}
			else if (i >= 3 && i < 6) {
				/////////y//////////////
				cubitos[i]->vertex[192 + 6] = 0.3f; //p1
				cubitos[i]->vertex[200 + 6] = 0.6f; //p2
				cubitos[i]->vertex[208 + 6] = 0.6f; //p3
				cubitos[i]->vertex[216 + 6] = 0.6f; //p4
				cubitos[i]->vertex[224 + 6] = 0.3f; //p5
				cubitos[i]->vertex[232 + 6] = 0.3f; //p6

			}
			else if (i >= 6)
			{
				cubitos[i]->vertex[192 + 6] = 0.6f; //p1
				cubitos[i]->vertex[200 + 6] = 1.0f; //p2
				cubitos[i]->vertex[208 + 6] = 1.0f; //p3
				cubitos[i]->vertex[216 + 6] = 1.0f; //p4
				cubitos[i]->vertex[224 + 6] = 0.6f; //p5
				cubitos[i]->vertex[232 + 6] = 0.6f; //p6
			}

			/////////////////x//////
			cubitos[i]->vertex[192 + 7] = 0.3f + float(tmp) / 10; //p1
			cubitos[i]->vertex[200 + 7] = 0.3f + float(tmp) / 10; //p2
			cubitos[i]->vertex[208 + 7] = 0.0f + float(tmp) / 10; //p3
			cubitos[i]->vertex[216 + 7] = 0.0f + float(tmp) / 10; //p4
			cubitos[i]->vertex[232 + 7] = 0.3f + float(tmp) / 10; //p6
			if (tmp == 6)
			{
				cubitos[i]->vertex[192 + 7] = 1.0f;
				cubitos[i]->vertex[200 + 7] = 1.0f;
				//cubitos[i]->vertex[216 + 7] = 1.0f;
				cubitos[i]->vertex[232 + 7] = 1.0;
			}
			cubitos[i]->vertex[224 + 7] = 0.0f + float(tmp) / 10; //p5

			for (int j = 192; j < 240; j += 8)
			{
				cubitos[i]->vertex[j + 4] = 1.0f;
				cubitos[i]->vertex[j + 3] = 0.4f;
				cubitos[i]->vertex[j + 5] = 0.4f;
			}
			tmp += 3;
			tmp %= 9;
		}
		//################################
		/////cara ABAJO
		tmp = 0;
		for (int i = 18; i < 27; i++) {
			if (i < 21) {
				////////////y//////////////
				cubitos[i]->vertex[144 + 6] = 0.0f; //p1
				cubitos[i]->vertex[152 + 6] = 0.3f; //p2
				cubitos[i]->vertex[160 + 6] = 0.3f; //p3
				cubitos[i]->vertex[168 + 6] = 0.3f; //p4
				cubitos[i]->vertex[176 + 6] = 0.0f; //p5
				cubitos[i]->vertex[184 + 6] = 0.0f; //p6
			}
			else if (i >= 21 && i < 24) {
				/////////y//////////////
				cubitos[i]->vertex[144 + 6] = 0.3f; //p1
				cubitos[i]->vertex[152 + 6] = 0.6f; //p2
				cubitos[i]->vertex[160 + 6] = 0.6f; //p3
				cubitos[i]->vertex[168 + 6] = 0.6f; //p4
				cubitos[i]->vertex[176 + 6] = 0.3f; //p5
				cubitos[i]->vertex[184 + 6] = 0.3f; //p6

			}
			else if (i >= 24)
			{
				cubitos[i]->vertex[144 + 6] = 0.6f; //p1
				cubitos[i]->vertex[152 + 6] = 1.0f; //p2
				cubitos[i]->vertex[160 + 6] = 1.0f; //p3
				cubitos[i]->vertex[168 + 6] = 1.0f; //p4
				cubitos[i]->vertex[176 + 6] = 0.6f; //p5
				cubitos[i]->vertex[184 + 6] = 0.6f; //p6
			}

			/////////////////x//////
			cubitos[i]->vertex[144 + 7] = 0.3f + float(tmp) / 10; //p1
			cubitos[i]->vertex[152 + 7] = 0.3f + float(tmp) / 10; //p2
			cubitos[i]->vertex[160 + 7] = 0.0f + float(tmp) / 10; //p3
			cubitos[i]->vertex[168 + 7] = 0.0f + float(tmp) / 10; //p4
			cubitos[i]->vertex[184 + 7] = 0.3f + float(tmp) / 10; //p6
			if (tmp == 6)
			{
				cubitos[i]->vertex[144 + 7] = 1.0f;
				cubitos[i]->vertex[152 + 7] = 1.0f;
				//cubitos[i]->vertex[216 + 7] = 1.0f;
				cubitos[i]->vertex[184 + 7] = 1.0;
			}
			cubitos[i]->vertex[168 + 7] = 0.0f + float(tmp) / 10; //p5
			for (int j = 144; j < 192; j += 8)
			{
				cubitos[i]->vertex[j + 4] = 1.0f;
				cubitos[i]->vertex[j + 3] = 1.0f;
				cubitos[i]->vertex[j + 5] = 1.0f;
			}
			tmp += 3;
			tmp %= 9;
		}
		//////////////

		//############CARA DERECHA############
		for (int i = 6; i < 9; ++i)
		{
			
			for (int j = 0; j < 48; j += 8)
			{
				cubitos[i]->vertex[j + 3] = 1.f;
			}
		}
		for (int i = 15; i < 18; ++i)
		{
			for (int j = 0; j < 48; j += 8)
			{
				cubitos[i]->vertex[j + 3] = 1.f;
			}


		}
		for (int i = 24; i < 27; ++i)
		{
			for (int j = 0; j < 48; j += 8)
			{
				cubitos[i]->vertex[j + 3] = 1.f;
			}
		}
		//####################################

		//############CARA IZQUIERDA############
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 240; j < 288; j += 8)
			{
				cubitos[i]->vertex[j + 3] = 1.0f;
				cubitos[i]->vertex[j + 4] = 1.0f;
			}
		}
		
		for (int i = 9; i < 12; ++i)
		{
			for (int j = 240; j < 288; j += 8)
			{
				cubitos[i]->vertex[j + 3] = 1.0f;
				cubitos[i]->vertex[j + 4] = 1.0f;
			}
		}
		for (int i = 18; i < 21; ++i)
		{
			for (int j = 240; j < 288; j += 8)
			{
				cubitos[i]->vertex[j + 3] = 1.0f;
				cubitos[i]->vertex[j + 4] = 1.0f;
			}
		}
		//####################################

		//#########CARA atraz######################
		for (int i = 0; i < 7; i+=3)
		{
			for (int j = 96; j < 144; j += 8)
			{
				cubitos[i + 2]->vertex[j + 5] = 0.5f;
				cubitos[i + 2]->vertex[j + 3] = 1.f;
			}
		}
		for (int i = 0; i < 7; i += 3)
		{
			for (int j = 96; j < 144; j += 8)
			{
				cubitos[i + 11]->vertex[j + 5] = 0.5f;
				cubitos[i + 11]->vertex[j + 3] = 1.f;
			}
		}
		for (int i = 0; i < 7; i += 3)
		{
			for (int j = 96; j < 144; j += 8)
			{
				cubitos[i + 20]->vertex[j + 5] = 0.5f;
				cubitos[i + 20]->vertex[j + 3] = 1.f;
			}
		}
		
	}
	void rotateXF(int x) {
		Cube1* tmp1 = nullptr;
		Cube1* tmp2 = nullptr;
		Cube1* tmp3 = nullptr;
		x *= 3;
		tmp1 = cubitos[0 + x];
		tmp2 = cubitos[9 + x];
		cubitos[0 + x] = cubitos[2 + x];
		cubitos[9 + x] = cubitos[1 + x];
		tmp3 = cubitos[18 + x];
		cubitos[18 + x] = tmp1;
		tmp1 = cubitos[19 + x];
		cubitos[19 + x] = tmp2;
		tmp2 = cubitos[20 + x];
		cubitos[20 + x] = tmp3;
		tmp3 = cubitos[11 + x];
		cubitos[11 + x] = tmp1;
		cubitos[2 + x] = tmp2;
		cubitos[1 + x] = tmp3;
	}
	void rotateXIF(int x) {
		//	std::cout << "RZ" << " " << x << std::endl;
		Cube1* tmp1 = nullptr;
		Cube1* tmp2 = nullptr;
		Cube1* tmp3 = nullptr;
		x *= 3;
		tmp1 = cubitos[0 + x];
		tmp2 = cubitos[1 + x];
		cubitos[0 + x] = cubitos[18 + x];
		cubitos[1 + x] = cubitos[9 + x];
		tmp3 = cubitos[2 + x];
		cubitos[2 + x] = tmp1;
		tmp1 = cubitos[11 + x];
		cubitos[11 + x] = tmp2;
		tmp2 = cubitos[20 + x];
		cubitos[20 + x] = tmp3;
		tmp3 = cubitos[19 + x];
		cubitos[19 + x] = tmp1;
		cubitos[18 + x] = tmp2;
		cubitos[9 + x] = tmp3;
	}
   	void rotateZF(int x) {
	//	std::cout << "RZ" << " " << x << std::endl;
		Cube1* tmp1 = nullptr;
		Cube1* tmp2 = nullptr;
		Cube1* tmp3 = nullptr;
		tmp1 = cubitos[6 + x];
		tmp2 = cubitos[15 + x];
		cubitos[6 + x] = cubitos[0 + x];
		cubitos[15 + x] = cubitos[3 + x];
		tmp3 = cubitos[24 + x];
		cubitos[24 + x] = tmp1;
		tmp1 = cubitos[21 + x];
		cubitos[21 + x] = tmp2;
		tmp2 = cubitos[18 + x];
		cubitos[18 + x] = tmp3;
		tmp3 = cubitos[9 + x];
		cubitos[9 + x] = tmp1;
		cubitos[0 + x] = tmp2;
		cubitos[3 + x] = tmp3;
	}
	void rotateZIF(int x) {
		//	std::cout << "RZ" << " " << x << std::endl;
		Cube1* tmp1 = nullptr;
		Cube1* tmp2 = nullptr;
		tmp1 = cubitos[0 + x];
		tmp2 = cubitos[3 + x];
		cubitos[0 + x] = cubitos[6 + x];
		cubitos[3 + x] = cubitos[15 + x];
		cubitos[6 + x] = cubitos[24 + x];
		cubitos[15 + x] = cubitos[21 + x];
		cubitos[24 + x] = cubitos[18 + x];
		cubitos[21 + x] = cubitos[9 + x];
		cubitos[18 + x] = tmp1;
		cubitos[9 + x] = tmp2;
	}
	void rotateYF(int x) {
		Cube1* tmp1 = nullptr;
		Cube1* tmp2 = nullptr;
		Cube1* tmp3 = nullptr;
		x *= 9;
		tmp1 = cubitos[2 + x];
		tmp2 = cubitos[5 + x];
		cubitos[2 + x] = cubitos[0 + x];
		cubitos[5 + x] = cubitos[1 + x];
		tmp3 = cubitos[8 + x];
		cubitos[8 + x] = tmp1;
		tmp1 = cubitos[7 + x];
		cubitos[7 + x] = tmp2;
		tmp2 = cubitos[6 + x];
		cubitos[6 + x] = tmp3;
		tmp3 = cubitos[3 + x];
		cubitos[3 + x] = tmp1;
		cubitos[0 + x] = tmp2; 
		cubitos[1 + x] = tmp3;
	}
	void rotateYIF(int x) {
		//	std::cout << "RZ" << " " << x << std::endl;
		Cube1* tmp1 = nullptr;
		Cube1* tmp2 = nullptr;
		x *= 9;
		tmp1 = cubitos[2 + x];
		tmp2 = cubitos[5 + x];
		cubitos[2 + x] = cubitos[8 + x];
		cubitos[5 + x] = cubitos[7 + x];
		cubitos[8 + x] = cubitos[6 + x];
		cubitos[7 + x] = cubitos[3 + x];
		cubitos[6 + x] = cubitos[0 + x];
		cubitos[3 + x] = cubitos[1 + x];
		cubitos[0 + x] = tmp1;
		cubitos[1 + x] = tmp2;
	}
	void FINAL() {
		if (FinalX1[0] == 2)
		{
			//std::cout << "FinalX1" << std::endl;
			rotateVertexX1(90);
			rotateXF(0);
			FinalX1[0] = 0;
			ix++;
		}
		else if (FinalX1[1] == 2)
		{
			//std::cout << "FinalX1" << std::endl;
			rotateVertexX1(-90);
			rotateXIF(0);
			FinalX1[1] = 0;
			ix++;
		}
		else if (FinalX2[0] == 2)
		{
			//std::cout << "FinalX2" << std::endl;
			rotateVertexX2(90);
			rotateXF(1);
			FinalX2[0] = 0;
			ix++;
		}
		else if (FinalX2[1] == 2)
		{
			//std::cout << "FinalX2" << std::endl;
			rotateVertexX2(-90);
			rotateXIF(1);
			FinalX2[1] = 0;
			ix++;
		}
		else if (FinalX3[0] == 2)
		{
			//std::cout << "FinalX3" << std::endl;
			rotateVertexX3(90);
			rotateXF(2);
			FinalX3[0] = 0;
			ix++;
		}
		else if (FinalX3[1] == 2)
		{
			//std::cout << "FinalX3" << std::endl;
			rotateVertexX3(-90);
			rotateXIF(2);
			FinalX3[1] = 0;
			ix++;
		}
		else if (FinalZ1[0] == 2)
		{
			//std::cout << "FinalZ1" << std::endl;
			rotateVertexZ1(-90);
			rotateZF(0);
			FinalZ1[0] = 0;
			ix++;
		}
		else if (FinalZ1[1] == 2)
		{
			//std::cout << "FinalZ1" << std::endl;
			rotateVertexZ1(90);
			rotateZIF(0);
			FinalZ1[1] = 0;
			ix++;
		}
		else if(FinalZ2[0] == 2)
		{
			//std::cout << "FinalZ2" << std::endl;
			rotateVertexZ2(-90);
			rotateZF(1);
			FinalZ2[0] = 0;
			ix++;
		}
		else if (FinalZ2[1] == 2)
		{
			//std::cout << "FinalZ2" << std::endl;
			rotateVertexZ2(90);
			rotateZIF(1);
			FinalZ2[1] = 0;
			ix++;
		}
		else if (FinalZ3[0] == 2)
		{
			//std::cout << "FinalZ3" << std::endl;
			rotateVertexZ3(-90);
			rotateZF(2);
			FinalZ3[0] = 0;
			ix++;
		}
		else if (FinalZ3[1] == 2)
		{
			//std::cout << "FinalZ3" << std::endl;
			rotateVertexZ3(90);
			rotateZIF(2);
			FinalZ3[1] = 0;
			ix++;
		}
		else if (FinalY1[0] == 2)/////////////////////////////////////
		{
			//std::cout << "FinalZ3" << std::endl;
			rotateVertexY1(-90);
			rotateYF(0);
			FinalY1[0] = 0;
			ix++;
		}
		else if (FinalY1[1] == 2)
		{
			//std::cout << "FinalZ3" << std::endl;
			rotateVertexY1(90);
			rotateYIF(0);
			FinalY1[1] = 0;
			ix++;
		}
		else if (FinalY3[0] == 2)
		{
		//	std::cout << "FinalY3" << std::endl;
			rotateVertexY3(-90);
			rotateYF(2);
			FinalY3[0] = 0;
			ix++;
		}
		else if (FinalY3[1] == 2)
		{
			//std::cout << "FinalZ3" << std::endl;
			rotateVertexY3(90);
			rotateYIF(2);
			FinalY3[1] = 0;
			ix++;
		}
	}
	void BeforeFINAL(bool &x) {
		if (FinalX1[0] == 1 && x)
		{
			x = false;
			FinalX1[0] = 2;	
		}
		else if (FinalX2[0] == 1 && x)
		{
			x = false;
			FinalX2[0] = 2;
		}
		else if (FinalX3[0] == 1 && x)
		{
			x = false;
			FinalX3[0] = 2;
		}
		else if (FinalX1[1] == 1 && x)
		{
			x = false;
			FinalX1[1] = 2;
		}
		else if (FinalX2[1] == 1 && x)
		{
			x = false;
			FinalX2[1] = 2;
		}
		else if (FinalX3[1] == 1 && x)
		{
			x = false;
			FinalX3[1] = 2;
		}
		else if (FinalZ1[0] == 1 && x)
		{
				x = false;
				FinalZ1[0] = 2;
		}
		else if (FinalZ2[0] == 1 && x)
		{
				x = false;
				FinalZ2[0] = 2;
		}
		else if (FinalZ3[0] == 1 && x)
		{
				x = false;
				FinalZ3[0] = 2;
		}
		else if (FinalZ1[1] == 1 && x)
		{
			x = false;
			FinalZ1[1] = 2;
		}
		else if (FinalZ2[1] == 1 && x)
		{
			x = false;
			FinalZ2[1] = 2;
		}
		else if (FinalZ3[1] == 1 && x)
		{
			x = false;
			FinalZ3[1 ] = 2;
		}
		else if (FinalY1[0] == 1 && x)///////////////////////
		{
			x = false;
			FinalY1[0] = 2;
		}
		else if (FinalY3[0] == 1 && x)
		{
			x = false;
			FinalY3[0] = 2;
		}
		else if (FinalY1[1] == 1 && x)
		{
			x = false;
			FinalY1[1] = 2;
		}
		else if (FinalY3[1] == 1 && x)
		{
			x = false;
			FinalY3[1] = 2;
		}
	}
	std::string format(std::string s) {
		std::string formatted;

		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '\' ') {
				formatted += s[i - 1];
				formatted += s[i - 1];
			}
			else if (s[i] == '2') {
				formatted += s[i - 1];
			}
			else if (s[i] == ' ') {

			}
			else {
				formatted += s[i];
			}
		}

		return formatted;

	}
	~rubic() {
		for (int i = 0; i < 27; ++i)
		{
			glDeleteVertexArrays(1, &(cubitos[i]->VAO));
			glDeleteBuffers(1, &(cubitos[i]->VBO));
			delete cubitos[i];
		}
	}
};
#endif