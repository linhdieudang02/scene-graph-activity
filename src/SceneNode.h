#ifndef SCENENODE_H
#define SCENENODE_H

#include <BasicGraphics.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class SceneNode {
public:
    SceneNode();
    SceneNode(glm::mat4 transform);
    SceneNode(std::shared_ptr<basicgraphics::Box> &box);
    SceneNode(glm::mat4 transform, std::shared_ptr<basicgraphics::Box> &box);
    
    virtual ~SceneNode() {}
    
    void setTransform(glm::mat4 transform);
    void addChild(std::shared_ptr<SceneNode> &child);
    void draw(basicgraphics::GLSLProgram &shader, const glm::mat4 &modelMatrix);
    
private:
    std::shared_ptr<basicgraphics::Box> _box;
    glm::mat4 _tranform;
    std::vector< std::shared_ptr<SceneNode> > _children;
};

#endif //SCENENODE_H
