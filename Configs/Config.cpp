#include "Config.h"
#include "../main.h"
#include "skins.h"

using namespace std;

Config* skins_cfg = new Config();
SkinList skin;

const char* Config;
string user = getenv("USER");
string skins = "/Users/"+user+"/Noriaela/configs/skins.cfg";

bool DoesDirectoryExist(const char* path) {
    struct stat info;
    return stat(path, &info) == 0 && S_ISDIR(info.st_mode);
}

int GetIntValue(bool Value) {
    return Value;
}

float GetFloatValue(float Value) {
    return Value;
}

bool fileExist(const char* path) {
    struct stat info;
    return stat(path, &info) == 0 && S_ISREG(info.st_mode);
}

void Config::CreateConfigDirectory() {
    string usr = getenv("USER");
    string start = "/USER/" + usr + "Noriaela";
    string end = "/Users/" + usr = "Noriaela/configs/";

    if(!DoesDirectoryExist(start.c_str()))
        mkdir(start.c_str(), 0777);
    if(!DoesDirectoryExist(end.c_str()))
        mkdir(end.c_str(), 0777);
}

void Config::SaveSkins() {
    
    skins_cfg.SetUnicode(true);
    this->CreateConfigDirectory();

    skins_cfg.SetDoubleValue("Knife", "CT Knife", GetFloatValue(skin.KnifeCT));    
    skins_cfg.SetDoubleValue("Knife", "T Knife", GetFloatValue(skin.KnifeT));
    skins_cfg.SetDoubleValue("Knife", "CT Knife ID", GetFloatValue(skin.KnifeID));
    skins_cfg.SetDoubleValue("Knife", "T Knife ID", GetFloatValue(skin.KnifeID));
    
    skins_cfg.SetDoubleValue("Rifles", "Galil", GetFloatValue(skin.galil));
    skins_cfg.SetDoubleValue("Rifles", "Famas", GetFloatValue(skin.famas));
    skins_cfg.SetDoubleValue("Rifles", "AK47", GetFloatValue(skin.ak47));
    skins_cfg.SetDoubleValue("Rifles", "M4A4", GetFloatValue(skin.m4a4));
    skins_cfg.SetDoubleValue("Rifles", "M4A1S", GetFloatValue(skin.m4a1));
    skins_cfg.SetDoubleValue("Rifles", "Scout", GetFloatValue(skin.scout));
    skins_cfg.SetDoubleValue("Rifles", "SG", GetFloatValue(skin.sg));
    skins_cfg.SetDoubleValue("Rifles", "AUG", GetFloatValue(skin.aug));
    skins_cfg.SetDoubleValue("Rifles", "AWP", GetFloatValue(skin.awp));
    skins_cfg.SetDoubleValue("Rifles", "G3SG1", GetFloatValue(skin.g3));
    skins_cfg.SetDoubleValue("Rifles", "Scar 20", GetFloatValue(skin.scar));
    
    skins_cfg.SetDoubleValue("Pistols", "Glock", GetFloatValue(skin.glock));
    skins_cfg.SetDoubleValue("Pistols", "USP", GetFloatValue(skin.usp));
    skins_cfg.SetDoubleValue("Pistols", "P2000", GetFloatValue(skin.p2000));
    skins_cfg.SetDoubleValue("Pistols", "Dual", GetFloatValue(skin.dual));
    skins_cfg.SetDoubleValue("Pistols", "P250", GetFloatValue(skin.p250));
    skins_cfg.SetDoubleValue("Pistols", "Tec 9", GetFloatValue(skin.tec9));
    skins_cfg.SetDoubleValue("Pistols", "Five Seven", GetFloatValue(skin.five7));
    skins_cfg.SetDoubleValue("Pistols", "CZ 75", GetFloatValue(skin.cz));
    skins_cfg.SetDoubleValue("Pistols", "Deagle", GetFloatValue(skin.deagle));
    skins_cfg.SetDoubleValue("Pistols", "R8", GetFloatValue(skin.revolver));
    
    skins_cfg.SetDoubleValue("SMGs", "Mac 10", GetFloatValue(skin.mac10));
    skins_cfg.SetDoubleValue("SMGs", "MP9", GetFloatValue(skin.mp9));
    skins_cfg.SetDoubleValue("SMGs", "MP7", GetFloatValue(skin.mp7));
    skins_cfg.SetDoubleValue("SMGs", "UMP", GetFloatValue(skin.ump));
    skins_cfg.SetDoubleValue("SMGs", "P90", GetFloatValue(skin.p90));
    skins_cfg.SetDoubleValue("SMGs", "Bizon", GetFloatValue(skin.bizon));
    
    skins_cfg.SetDoubleValue("Heavy", "Nova", GetFloatValue(skin.nova));
    skins_cfg.SetDoubleValue("Heavy", "Sawed off", GetFloatValue(skin.sawed));
    skins_cfg.SetDoubleValue("Heavy", "Mag 7", GetFloatValue(skin.mag7));
    skins_cfg.SetDoubleValue("Heavy", "XM", GetFloatValue(skin.xm));
    skins_cfg.SetDoubleValue("Heavy", "M249", GetFloatValue(skin.m249));
    skins_cfg.SetDoubleValue("Heavy", "Negev", GetFloatValue(skin.negev));
    
    skins_cfg.SaveFile(skins.c_str());
    
}

void Config::LoadSkins() {
    this->CreateConfigDirectory();
    if(!fileExist(skins.c_str()))
        SaveSkins();
    skins_cfg.SetUnicode(true);
    skins_cfg.LoadFile(skins.c_str());
    
    skin.KnifeCT = skin_cfgget_f("Knife", "T Knife");
    skin.KnifeCT = skin_cfgget_f("Knife", "CT Knife");
    skin.KnifeID = skin_cfgget_f("Knife", "T Knife ID");
    skin.KnifeID = skin_cfgget_f("Knife", "CT Knife ID");

    skin.galil   = skin_cfgget_f("Rifles", "Galil");
    skin.famas   = skin_cfgget_f("Rifles", "Famas");
    skin.ak47    = skin_cfgget_f("Rifles", "AK47");
    skin.m4a4    = skin_cfgget_f("Rifles", "M4A4");
    skin.m4a1    = skin_cfgget_f("Rifles", "M4A1S");
    skin.scout   = skin_cfgget_f("Rifles", "Scout");
    skin.sg      = skin_cfgget_f("Rifles", "SG");
    skin.aug     = skin_cfgget_f("Rifles", "AUG");
    skin.awp     = skin_cfgget_f("Rifles", "AWP");
    skin.g3      = skin_cfgget_f("Rifles", "G3SG1");
    skin.scar    = skin_cfgget_f("Rifles", "Scar 20");
    
    skin.glock   = skin_cfgget_f("Pistols", "Glock");
    skin.usp     = skin_cfgget_f("Pistols", "USP");
    skin.p2000   = skin_cfgget_f("Pistols", "P2000");
    skin.dual    = skin_cfgget_f("Pistols", "Dual");
    skin.p250    = skin_cfgget_f("Pistols", "P250");
    skin.tec9    = skin_cfgget_f("Pistols", "Tec 9");
    skin.five7   = skin_cfgget_f("Pistols", "Five Seven");
    skin.cz      = skin_cfgget_f("Pistols", "CZ 75");
    skin.deagle  = skin_cfgget_f("Pistols", "Deagle");
    skin.revolver= skin_cfgget_f("Pistols", "R8");
    
    skin.mac10   = skin_cfgget_f("SMGs", "Mac 10");
    skin.mp9     = skin_cfgget_f("SMGs", "MP9");
    skin.mp7     = skin_cfgget_f("SMGs", "MP7");
    skin.ump     = skin_cfgget_f("SMGs", "UMP");
    skin.p90     = skin_cfgget_f("SMGs", "P90");
    skin.bizon   = skin_cfgget_f("SMGs", "Bizon");
    // Heavy
    skin.nova    = skin_cfgget_f("Heavy", "Nova");
    skin.sawed   = skin_cfgget_f("Heavy", "Sawed off");
    skin.mag7    = skin_cfgget_f("Heavy", "Mag 7");
    skin.xm      = skin_cfgget_f("Heavy", "XM");
    skin.m249    = skin_cfgget_f("Heavy", "M249");
    skin.negev   = skin_cfgget_f("Heavy", "Negev");
}