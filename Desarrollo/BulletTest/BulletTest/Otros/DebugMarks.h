#pragma once
#include <EntActive.h>
#include <Character.h>
#include <Time.hpp>
#include <Color4f.h>

//Creates a billboard in the position of the entity
class DebugMarks : public EntActive{
public:
	DebugMarks(Character* ent, float yOffset);
	~DebugMarks();

	// Heredado vía Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;
	virtual void handleMessage(const Message & message) override;
	virtual bool handleTrigger(TriggerRecordStruct * Trigger) override;
	virtual std::string getClassName() override { return "DebugMarks"; }
	virtual void setPosition(const Vec3<float>& vec) override;

	//Activates mark during the time passed and the color desired (if time -1 keeps activated indefinitely)
	void activateMark(Time time, const Vec3<float> color);

	bool isActive() const { return mIsActive;  }

	void syncRecevied();

private:

	//Entity sobre la que se posiciona
	Character* m_ent;

	Time m_lifetime;

	Time losedConnection;

	Clock mlastSyncPacket;

	Clock mbillboardTime;

	bool mIsActive;

	float entYOffset;
};