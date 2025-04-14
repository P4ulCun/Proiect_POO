

template <typename T>
class Singleton
{
public:
	Singleton() = default;

	static T& getInstance()
	{
		static T instance;
		return instance;
	}
};