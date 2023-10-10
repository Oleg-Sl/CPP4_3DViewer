#ifndef _3DVIEWER_VIEW_INCLUDE_NANAGERSCENEOBSERVERBASE_H_
#define _3DVIEWER_VIEW_INCLUDE_NANAGERSCENEOBSERVERBASE_H_

#include "managersceneobserverbase.h"
#include "sceneparameters.h"

#include <list>


namespace s21 {

class ManagerSceneObservertBase {
public:
    virtual void Update(SceneParameters&) = 0;
};

} // namespace s21

#endif // _3DVIEWER_VIEW_INCLUDE_NANAGERSCENEOBSERVERBASE_H_
