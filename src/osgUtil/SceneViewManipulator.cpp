#include <osgUtil/SceneViewManipulator>
#include <osgUtil/TrackballManipulator>

using namespace osgUtil;

SceneViewManipulator::SceneViewManipulator():
                                            _cm(osgNew TrackballManipulator),
                                            _gm(osgNew StateSetManipulator)
{
}

SceneViewManipulator::~SceneViewManipulator()
{
}

void SceneViewManipulator::setSceneView(SceneView* sv)
{
    _sv=sv;
    _cm->setNode(sv->getSceneData());
    _cm->setCamera(sv->getCamera());
    _gm->setStateSet(sv->getGlobalStateSet());
}

SceneView *SceneViewManipulator::getSceneView()
{
    return _sv.get();
}

const SceneView *SceneViewManipulator::getSceneView() const
{
    return _sv.get();
}

bool SceneViewManipulator::handle(const GUIEventAdapter& ea,GUIActionAdapter& aa)
{
    if(_cm->handle(ea,aa)) return true;
    if(_gm->handle(ea,aa)) return true;
    return false;
}
