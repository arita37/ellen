#pragma once
#ifndef LOGGER_H
#define LOGGER_H

class logger {
public:
	bool trials;
	logger(){trials=false;}	// Opens a file for use with ofstream fout.
	~logger(){fout.close();}			// Flushes and closes the logging file.
	void set(bool t) {trials=t;};
	void open(std::string& filename){fout.open(filename);}
	void close(){fout.close();}
	//logger& operator(); // Allows us to set the mask in the same line as the messages

	template<class T>
	friend logger& operator<<( logger& log, const T& output );


	std::ofstream fout;
	//unsigned mask;
};

template<class T>
logger& operator<<( logger& log, const T& output ) {

	if(!log.trials) std::cout << output;
	log.fout << output;
	return log;
}
#endif