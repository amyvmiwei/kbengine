# -*- coding: utf-8 -*-
import KBEngine
from KBEDebug import *
from interfaces.GameObject import GameObject

class NPCObject(GameObject):
	def __init__(self):
		GameObject.__init__(self)

	def onDestroy(self):
		"""
		entity销毁
		"""
		if self.spawnID > 0:
			spawner = KBEngine.entities.get(self.spawnID)
			if spawner:
				spawner.onEntityDestroyed(self.entityNO)
				
NPCObject._timermap = {}
NPCObject._timermap.update(GameObject._timermap)