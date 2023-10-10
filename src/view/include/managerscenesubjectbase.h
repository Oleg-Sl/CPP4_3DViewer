#ifndef _3DVIEWER_VIEW_INCLUDE_NANAGERSCENESUBJECTBASE_H_
#define _3DVIEWER_VIEW_INCLUDE_NANAGERSCENESUBJECTBASE_H_


#include "managersceneobserverbase.h"

#include <list>


namespace s21 {

class ManagerSceneSubjectBase {
public:
    virtual void Subscribe(ManagerSceneObservertBase *observer) = 0;
    virtual void Unsubscribe(ManagerSceneObservertBase *observer) = 0;
    virtual void Notify() = 0;

};

} // namespace s21

#endif // _3DVIEWER_VIEW_INCLUDE_NANAGERSCENESUBJECTBASE_H_
