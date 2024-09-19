#include <iostream>
#include <fstream>
#include <string>
#include "dependencies/include/nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;


struct Fabric
{
	int id;
	string hash;
	string ref;
	string rf;
	string ip;
	string density;
	string thickness;
};

struct Clothing
{
	int id;
	string hash;
	string covering;
	Fabric fabric;
};

struct Environment
{
	int id;
	string hash;
	string typeEnv;
	int temperatureInCelsius;
	int humidityInPercent;
	int windVelocity;
};

struct Torso
{
	Environment Environment;
	Clothing Clothing;
};


struct Head
{
	Environment Environment;
};

struct Body
{
	int id;
	string hash;
	Head head;
	Torso torso;
};

struct Response
{
	Body body;
};

struct MyModel
{
	Response response;
};

MyModel jsonToModel(const json& jsonString) {

	MyModel model;

	model.response.body.id = jsonString.at("body").at("id").get<int>();
	model.response.body.hash = jsonString.at("body").at("hash").get<string>();
	
	model.response.body.head.Environment.id = jsonString.at("body").at("head").at("Environment").at("id").get<int>();
	model.response.body.head.Environment.hash = jsonString.at("body").at("head").at("Environment").at("hash").get<string>();
	model.response.body.head.Environment.typeEnv = jsonString.at("body").at("head").at("Environment").at("typeEnv").get<string>();
	model.response.body.head.Environment.temperatureInCelsius = jsonString.at("body").at("head").at("Environment").at("temperatureInCelsius").get<int>();
	model.response.body.head.Environment.humidityInPercent = jsonString.at("body").at("head").at("Environment").at("humidityInPercent").get<int>();
	model.response.body.head.Environment.windVelocity = jsonString.at("body").at("head").at("Environment").at("windVelocity").get<int>();
	
	model.response.body.torso.Environment.id = jsonString.at("body").at("torso").at("Environment").at("id").get<int>();
	model.response.body.torso.Environment.hash = jsonString.at("body").at("torso").at("Environment").at("hash").get<string>();
	model.response.body.torso.Environment.typeEnv = jsonString.at("body").at("torso").at("Environment").at("typeEnv").get<string>();
	model.response.body.torso.Environment.temperatureInCelsius = jsonString.at("body").at("torso").at("Environment").at("temperatureInCelsius").get<int>();
	model.response.body.torso.Environment.humidityInPercent = jsonString.at("body").at("torso").at("Environment").at("humidityInPercent").get<int>();
	model.response.body.torso.Environment.windVelocity = jsonString.at("body").at("torso").at("Environment").at("windVelocity").get<int>();

	model.response.body.torso.Clothing.id = jsonString.at("body").at("torso").at("Clothing").at("id").get<int>();
	model.response.body.torso.Clothing.hash = jsonString.at("body").at("torso").at("Clothing").at("hash").get<string>();
	model.response.body.torso.Clothing.covering = jsonString.at("body").at("torso").at("Clothing").at("covering").get<string>();

	model.response.body.torso.Clothing.fabric.id = jsonString.at("body").at("torso").at("Clothing").at("fabric").at("id").get<int>();
	model.response.body.torso.Clothing.fabric.hash = jsonString.at("body").at("torso").at("Clothing").at("fabric").at("hash").get<string>();
	model.response.body.torso.Clothing.fabric.ref = jsonString.at("body").at("torso").at("Clothing").at("fabric").at("ref").get<string>();
	model.response.body.torso.Clothing.fabric.rf = jsonString.at("body").at("torso").at("Clothing").at("fabric").at("rf").get<string>();
	model.response.body.torso.Clothing.fabric.ip = jsonString.at("body").at("torso").at("Clothing").at("fabric").at("ip").get<string>();
	model.response.body.torso.Clothing.fabric.density = jsonString.at("body").at("torso").at("Clothing").at("fabric").at("density").get<string>();
	model.response.body.torso.Clothing.fabric.thickness = jsonString.at("body").at("torso").at("Clothing").at("fabric").at("thickness").get<string>();
	
	return model;
};


int main() {

	ifstream f("json1.json");
	json jsonString = json::parse(f);
	
	MyModel myModel = jsonToModel(jsonString);

	cout << myModel.response.body.torso.Environment.humidityInPercent;

	


};