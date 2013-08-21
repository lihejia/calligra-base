/*
 *  Copyright (c) 2011 Dmitry Kazakov <dimula73@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef __KIS_DUMMIES_FACADE_BASE_TEST_H
#define __KIS_DUMMIES_FACADE_BASE_TEST_H

#include <QtTest/QtTest>

#include "empty_nodes_test.h"

class KisNodeDummy;
class KisDummiesFacadeBase;

class KisDummiesFacadeBaseTest : public QObject, public TestUtil::EmptyNodesTest
{
    Q_OBJECT

public:
    virtual ~KisDummiesFacadeBaseTest();

protected:
    virtual KisDummiesFacadeBase* dummiesFacadeFactory() = 0;
    virtual void destroyDummiesFacade(KisDummiesFacadeBase *dummiesFacade) = 0;

private slots:
    void slotNodeActivated(KisNodeSP node);
    void slotEndInsertDummy(KisNodeDummy *dummy);
    void slotBeginRemoveDummy(KisNodeDummy *dummy);

private slots:
    void init();
    void cleanup();

    void testSetImage();
    void testAddNode();
    void testRemoveNode();
    void testMoveNodeSameParent();
    void testMoveNodeDifferentParent();
    void testSubstituteRootNode();
    void testAddSelectionMasksNoActivation();

private:
    void verifyActivatedNodes(const QString &nodes);
    void verifyMovedDummies(const QString &nodes);

private:
    KisDummiesFacadeBase *m_dummiesFacade;

    QString m_activatedNodes;
    QString m_movedDummies;
};

#endif /* __KIS_DUMMIES_FACADE_BASE_TEST_H */
