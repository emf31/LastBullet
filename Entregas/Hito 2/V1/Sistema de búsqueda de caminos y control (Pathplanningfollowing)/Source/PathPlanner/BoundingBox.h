#pragma once



class BoundingBox {
private:
	float m_top;
	float m_bot;
	float m_left;
	float m_right;

public:
	BoundingBox(float top, float left, float right, float bot) {
		m_top = top;
		m_bot = bot,
		m_left = left;
		m_right = right;
	}

	BoundingBox(){}

	float getTop() {
		return m_top;
	}

	float getBot() {
		return m_bot;
	}
	float getLeft() {
		return m_left;
	}
	float getRight() {
		return m_right;
	}
	//TODO hacer el metodo que te diga si esta colisionando con la celda
};