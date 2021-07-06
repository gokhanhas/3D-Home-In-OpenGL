Geliştirme Ortamı : MACOS Big Sur 11.3

- MacOs için ilk önce gerekli frameworkların kurulması gerekir.
	-> homebrew ( https://docs.brew.sh/Installation )
	-> brew install grew
	-> brew install glfw 
	
	- MacOs için derleme : 
		-> g++ main.cpp -framework OpenGL -framework GLUT - o app
		-> ./app


- Linux ortamları için derleme : (Hata verirse ilgili kütüphane yüklenmelidir.)	
	-> g++ main.cpp -lglut -lGL -lGLU -o app
	-> ./app
