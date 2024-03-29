#include "Object.h"
#include "Scene.h"
#include "GameObject.h"
using namespace SealEngine;

int Object::GetInstanceId() const { return _instanceId; }
const std::string& Object::ToString() const { return name; }


int Object::_instanceIdCounter = 0;

Object::Object(const std::string& name) : _instanceId(_instanceIdCounter++), name(name) {}
Object::Object(const Object& obj) : _instanceId(_instanceIdCounter++), name(obj.name + " (Clone)") {}
std::shared_ptr<Object> Object::Clone() const { return std::shared_ptr<Object>(_Clone()); }


Object::operator bool() const { return true; }
bool Object::operator==(const Object& obj) const { return GetInstanceId() == obj.GetInstanceId(); }
bool Object::operator!=(const Object& obj) const { return !this->operator==(obj); }

Object* Object::Instantiate(const Object& obj) {
	auto object = obj.Clone();

	if (auto gameObject = std::dynamic_pointer_cast<GameObject>(object)) {
		SceneManager::GetActiveScene()->instantiationQueue.emplace(gameObject);
	}
	//}else if(gameObject = dynamic_cast<MonoBehaviour*>(&obj)->gameObject){


	//	//SceneManager::scenes[SceneManager::currentSceneId]->gameObjects.push_back(x);

	//}
	//SceneManager::scenes[SceneManager::currentSceneId]->gameObjects.push_back(GameObject(Object obj));
	return object.get();
}

Object* Object::Instantiate(const Object& obj, const Vector3& position, Transform*)
{
	Object* object = Instantiate(obj);
	if (GameObject* gameObject = dynamic_cast<GameObject*>(object)) {
		gameObject->transform->position = position;
	}

	return object;
}

void Object::Destroy(Object& object, float delayDuration) {
	SceneManager::GetActiveScene()->destroyQueue.emplace(&object);
}

void Object::DestroyImmediate(Object object, bool allowDestroyingAssets) {
}

void Object::DontDestroyOnLoad(Object target) {
}
