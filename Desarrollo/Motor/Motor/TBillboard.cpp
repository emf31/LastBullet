#include "TBillboard.h"
#include "ResourceManager.h"
#include <glm/gtc/type_ptr.hpp>
#include "SceneManager.h"


TBillboard::TBillboard(TMeshGroup* meshGroup, Vec3<float> posicion) : sm(SceneManager::i()) {

	m_meshGroup = meshGroup;
	modelMatrix.resetMatrix();
	modelMatrix.setPosition(posicion);
	conVida = true;
	frameBillboard = 1;
	numFrames = 83;
	billBoardTimeFrame = seconds(0.008f);
	billboardCurrentTime.restart();
	m_scale = Vec3<float>(1.f, 1.f, 1.f);
}

TBillboard::~TBillboard() {

}

void TBillboard::draw()
{
	mvp = calcularMVP();
	selectCurrentFrame();
	sm.shaderBildboard->Use();
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, SceneManager::i().billboardFrameAnimation[frameBillboard]);
	glUniformMatrix4fv(glGetUniformLocation(sm.shaderBildboard->Program, "mvp"), 1, GL_FALSE, glm::value_ptr(mvp));

	//Dibujamos el modelo
	m_meshGroup->draw();

	
}

glm::mat4 TBillboard::calcularMVP()
{
	const glm::mat4& view = sm.getViewMatrix();
	const glm::mat4& projection = sm.getProjectionMatrix();

	glm::mat4 modelview = view * modelMatrix.getMatrix();

	modelview[0][0] = m_scale.getX();
	modelview[0][1] = 0.0;
	modelview[0][2] = 0.0;


	modelview[1][0] = 0.0;
	modelview[1][1] = m_scale.getY();
	modelview[1][2] = 0.0;

	modelview[2][0] = 0.0;
	modelview[2][1] = 0.0;
	modelview[2][2] = m_scale.getZ();

	return (projection * modelview);
}

void TBillboard::selectCurrentFrame()
{
	if (billboardCurrentTime.getElapsedTime().asMilliseconds() > billBoardTimeFrame.asMilliseconds()) {
		frameBillboard++;
		billboardCurrentTime.restart();
	}
	if (frameBillboard >= numFrames) {
		conVida = false;
	}
}

bool TBillboard::isAlive()
{
	return conVida;
}

