#include<iostream>
#include<memory>
#include<vector>
using namespace std;

class Build {
public:
    virtual ~Build() {}
    virtual string build() = 0;
};

class CMake : public Build {
public:
    string build() override {
        return "cmake --build .";
    }
};
class Meson : public Build {
public:
    string build() override {
        return "meson compile -C .";
    }

};
class Cargo : public Build {
public:
    string build() override {
        return "cargo build";
    }
};

class ProgrammingLanguage {
unique_ptr<Build> _build;
public:
    ProgrammingLanguage(){}
    ProgrammingLanguage(unique_ptr<Build> build) : _build(move(build)) {}
    virtual ~ProgrammingLanguage() {}
    virtual string print_line(const string &a) = 0;
    virtual string for_each(const string &a, const string &b) = 0;

    string build() {
        return _build->build();
    }
};

class Cpp : public ProgrammingLanguage {
public:
    Cpp() {}
    Cpp(unique_ptr<Build> build) : ProgrammingLanguage(move(build)) {}
    string print_line(const string &str) override {
       return "cout << \""+str+"\" << endl;";
    }
    string for_each(const string &e, const string &vec) {
        return "for(auto &"+e+": "+vec+") {}";
    }
};
class Rust : public ProgrammingLanguage {
public:
    Rust() {}
    Rust(unique_ptr<Build> build) : ProgrammingLanguage(move(build)) {}
    string print_line(const string &str) override {
        return "println!(\""+str+"\");";
    }
    string for_each(const string &e, const string &vec) {
        return "for "+e+" in &"+vec+" {}";

    }
};

void taskA() {
    vector<unique_ptr<ProgrammingLanguage>> programming_languages;
    // Uncommenting the following line should cause compilation error:
    //programming_languages.emplace_back(make_unique<ProgrammingLanguage>());
    programming_languages.emplace_back(make_unique<Cpp>());
    programming_languages.emplace_back(make_unique<Rust>());
    for (auto &programming_language : programming_languages) {
        cout << programming_language->print_line("Hello World") << endl;
        cout << programming_language->for_each("e", "vec") << endl << endl;
    }
}

void taskB() {
    vector<unique_ptr<ProgrammingLanguage>> programming_languages;
    programming_languages.emplace_back(make_unique<Cpp>(make_unique<CMake>()));
    programming_languages.emplace_back(make_unique<Cpp>(make_unique<Meson>()));
    programming_languages.emplace_back(make_unique<Rust>(make_unique<Cargo>()));
    for (auto &programming_language : programming_languages) {
        cout << programming_language->build() << endl;
    }
}
int main() {
    //taskA();
    taskB();
}
