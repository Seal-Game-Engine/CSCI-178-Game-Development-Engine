#include "Model.h"
#include "AssetManager.h"

void Model::DrawModel() {
    glPushMatrix();
    {
        glTranslatef(transform.position.x(), transform.position.y(), transform.position.z());
        glRotatef(transform.rotation.x(), 1, 0, 0);
        glRotatef(transform.rotation.y(), 0, 1, 0);
        glRotatef(transform.rotation.z(), 0, 0, 1);

        glBindTexture(GL_TEXTURE_2D, AssetManager::Googleplex.textureId());

        glutSolidTeapot(transform.scale.y());
    }
    glPopMatrix();
}

void Model::Update() {
    using namespace InputSystem;
    if (Inputs::GetKeyDown(KeyCode::UpArrow))
        transform.rotation -= Vector3::right() * 90;

    if (Inputs::GetKeyDown(KeyCode::DownArrow))
        transform.rotation += Vector3::right() * 90;

    if (Inputs::GetKeyDown(KeyCode::LeftArrow))
        transform.rotation -= Vector3::up() * 90;

    if (Inputs::GetKeyDown(KeyCode::RightArrow))
        transform.rotation += Vector3::up() * 90;

    Vector2 mouse = Inputs::GetMousePosition();
    transform.position = Vector3(mouse.x() / 100 - 3, -mouse.y() / 100, transform.position.z());
    

    if (Inputs::GetKeyDown(KeyCode::S))//S
        transform.position = Vector3::zero();

    //if (Inputs::GetKeyDown(0x57))//W
    //    transform.position.Set(transform.position.x(), transform.position.y() + 1, transform.position.z());

    //if (Inputs::GetKeyDown(0x53))//S
    //    transform.position.Set(transform.position.x(), transform.position.y() - 1, transform.position.z());

    //if (Inputs::GetKeyDown(0x41))//A
    //    transform.position.Set(transform.position.x() - 1, transform.position.y(), transform.position.z());

    //if (Inputs::GetKeyDown(0x44))//D
    //    transform.position.Set(transform.position.x() + 1, transform.position.y(), transform.position.z());

    if (Inputs::GetKeyDown(KeyCode::Plus))
        transform.position.Set(transform.position.x(), transform.position.y(), transform.position.z() + 1);

    if (Inputs::GetKeyDown(KeyCode::Minus))
        transform.position.Set(transform.position.x(), transform.position.y(), transform.position.z() - 1);

    if (InputSystem::Inputs::GetKeyDown(KeyCode::F1)) {
        ApplicationManager::TryToggleFullScreen();
    }
}
