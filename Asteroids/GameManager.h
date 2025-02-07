#pragma once

#include "raylib.h"

class GameManager
{
public:
	GameManager()  {}
	~GameManager() {}

	void Update(float a_DeltaTime);

	#pragma region Player Handling

public:
	int  GetScore() { return m_Score; }
	void AddScore(int a_Points);
	int  GetLives() { return m_PlayerLives; }
	void AddLives(int a_Lives) { m_PlayerLives += a_Lives; }
	void DisplayScore(int a_PosX, int a_PosY, Color a_Colour, int a_FontSize);
	void DisplayLives(int a_PosX, int a_PosY, Color a_Colour, int a_FontSize);

	// ===== On Death =====
	void DisplayDeathScreen(); 
	void RespawnPlayer();
	void Reset();
	bool m_GameOver = false;

private:
	int m_PlayerLives = 3;
	int m_Score = 0;

	#pragma endregion

	#pragma region Asteroid Spawn Handling

private:
	void SpawnAsteroids(float a_DeltaTime);
	void SpawnRandomAsteroid();

	float m_GameDifficulty = 1;
	float m_MaxGameDifficulty = 10;

	float m_TimeSinceLastSpawn = 0.0f; // The Time since the Last Asteroid was Spawned
	#pragma endregion
};

