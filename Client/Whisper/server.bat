call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x86_amd64
CD ..\..\..\
call setenv.cmd
CD bin
.\DCPSInfoRepo -ORBEndpoint iiop://localhost:12345 -d domain_ids
