build1:
	g++ -std=c++17 receiver.cpp -o r
build2:
	g++ -std=c++17 sender.cpp -o s
clean:
	sudo rm -rf f1 s r
clear:
	sudo rm -rf s r
