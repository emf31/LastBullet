#pragma once
#include "TAnimationGroupMesh.h"
#include "TTransform.h"
#include "AnimationReader.h"
#include "Clock.hpp"


class TAnimation : public TEntity {

public:
	/*  Funciones   */
	// Constructor, espera una ruta al recurso (y opcionalmente un shader).
	TAnimation(TAnimationGroupMesh* meshGroup);
	~TAnimation();




	bool setAnimation(const std::string& animName, int desde, int hasta);
	void setCurrentAnimation(const std::string& animName);
	void setFrameTime(Time time);

	void setPosition(Vec3<float> pos);
	void updatePosition(Vec3<float> pos);


	void setRotationXYZ(Vec3<float> rot);


	void setScale(Vec3<float> esc);
	Vec3<float> getRotation();
	Vec3<float> getPosition();
	Vec3<float> getScale();

	glm::mat4 getRotationMatrix();
	glm::mat4 getPositionMatrix();
	glm::mat4 getScaleMatrix();



	void setVisible(bool b) { visible = b; }
	bool isVisible() const { return visible; }


	void setModelColor(float r, float g, float b) {
		m_r = r;
		m_g = g;
		m_b = b;
	}



private:

	SceneManager &sm;



	bool visible;

	virtual void beginDraw();

	virtual void endDraw();

	TAnimationGroupMesh* meshes;

	//std::vector<TMeshGroup*> vectorModelos;
	std::vector<AnimationMesh*> currentAnimation;

	std::unordered_map<std::string, std::vector<AnimationMesh*>> animMap;
	int numAnims;
	int currentFrame;
	Time timeFrame;
	Clock currentTime;
	void selectCurrentFrame();

	float m_r;
	float m_g;
	float m_b;

	friend class SceneManager;
};