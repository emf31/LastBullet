#pragma once
#include "TAnimationGroupMesh.h"
#include "TTransform.h"
#include "AnimationReader.h"
#include "Clock.hpp"

struct CurrentAnim {
	std::vector<AnimationMesh*> animacion;
	bool paused;
	bool finished;
	bool loop;
};


class TAnimation : public TEntity {

public:

	TAnimation(TAnimationGroupMesh* meshGroup);
	~TAnimation();

	
	//Llamar a esto desencadena que todos los hijos de este TAnimation se borren
	virtual void removeEntity() override;


	bool setAnimation(const std::string& animName, int desde, int hasta, bool loop);
	void setCurrentAnimation(const std::string& animName);
	void setFrameTime(Time time);

	void setPosition(Vec3<float> pos);
	void updatePosition(Vec3<float> pos);

	void setPaused(bool a);
	void setLooped(bool a) { currentAnimation->loop = a; }
	void restartAnimation();
	bool isFinished() const { return currentAnimation->finished; }
	bool isPaused() const { return currentAnimation->paused; }
	bool isLooped() const { return currentAnimation->loop; }


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

	int getCurrentFrame() const { return currentFrame; }
	void setCurrentFrame(int frame) { currentFrame = frame; }



private:

	SceneManager &sm;



	bool visible;

	virtual void beginDraw();
	virtual void beginDrawSombras();

	virtual void endDraw();

	TAnimationGroupMesh* meshes;

	CurrentAnim* currentAnimation;

	std::vector<bool> whoIsLoop;

	std::unordered_map<std::string, CurrentAnim*> animMap;

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