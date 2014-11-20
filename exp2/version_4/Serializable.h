#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

class CSerializable
{
	public:
		virtual bool Serialize(int fd) = 0;
		virtual CSerializable * Deserialize(int fd) = 0;
		virtual int GetType() = 0;
};

#endif
