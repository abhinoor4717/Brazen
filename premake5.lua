{
	"c_cpp_properties.json": {
	  "configurations": [
		{
		  "name": "Windows",
		  "includePath": [
			"${workspaceFolder}/Ember/src",
			"${workspaceFolder}/Ember/vendor/spdlog/include",
			"${workspaceFolder}/Ember/vendor/SDL2/include"
		  ],
		  "defines": [
			"EM_PLATFORM_WINDOWS",
			"SDL_MAIN_HANDLED"
		  ],
		  "compilerPath": "C:/MinGW-64/bin/g++.exe",
		  "cStandard": "c17",
		  "cppStandard": "c++17",
		  "intelliSenseMode": "windows-gcc-x64"
		}
	  ],
	  "version": 4
	},
  
	"tasks.json": {
	  "version": "2.0.0",
	  "tasks": [
		{
		  "label": "Build Brazen",
		  "type": "shell",
		  "command": "g++",
		  "args": [
			"-IEmber/src",
			"-IEmber/vendor/spdlog/include",
			"-IEmber/vendor/SDL2/include",
			"-LEmber/vendor/SDL2/lib/mingw",
			"-o", "bin/Debug-windows-x64/Brazen/Brazen.exe",
			"Brazen/src/*.cpp",
			"-lSDL2main",
			"-lSDL2",
			"-lgdi32",
			"-luser32"
		  ],
		  "group": {
			"kind": "build",
			"isDefault": true
		  }
		}
	  ]
	},
  
	"launch.json": {
	  "version": "0.2.0",
	  "configurations": [
		{
		  "name": "Launch Brazen",
		  "type": "cppdbg",
		  "request": "launch",
		  "program": "${workspaceFolder}/bin/Debug-windows-x64/Brazen/Brazen.exe",
		  "args": [],
		  "stopAtEntry": false,
		  "cwd": "${workspaceFolder}",
		  "environment": [],
		  "externalConsole": true,
		  "MIMode": "gdb",
		  "setupCommands": [
			{
			  "description": "Enable pretty-printing for gdb",
			  "text": "-enable-pretty-printing",
			  "ignoreFailures": true
			}
		  ]
		}
	  ]
	}
  }
  