call CleanDependencies.bat

cd .\Ogre
call BuildOgre.bat
cd ..

cd .\Bullet
call BuildBullet.bat
cd ..

cd .\LUA
call BuildLua.bat
cd ..

cd .\CEGUI
call BuildCEGUI.bat
cd ..

cd .\FMOD
call BuildFMOD.bat
cd ..