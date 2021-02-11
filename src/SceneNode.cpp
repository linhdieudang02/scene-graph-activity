#include "SceneNode.h"

SceneNode::SceneNode(){
    _box = nullptr;
    _tranform = mat4(1.0);
}

SceneNode::SceneNode(glm::mat4 transform) : _tranform(transform){
    _box = nullptr;
}

SceneNode::SceneNode(std::shared_ptr<basicgraphics::Box> &box){
    _box = box;
    _tranform = mat4(1.0);
}

SceneNode::SceneNode(glm::mat4 transform, std::shared_ptr<basicgraphics::Box> &box){
    _box = box;
    _tranform = transform;
}


void SceneNode::setTransform(glm::mat4 transform){
    _tranform = transform;
}

void SceneNode::addChild(std::shared_ptr<SceneNode> &child){
    _children.push_back(child);
}

void SceneNode::draw(basicgraphics::GLSLProgram &shader, const glm::mat4 &modelMatrix){
    if (_box){
        _box->draw(shader, _tranform * modelMatrix);
    }
    for(auto iter = _children.begin(); iter != _children.end(); ++iter){
        (*iter)->draw(shader, _tranform * modelMatrix);
    }
}
