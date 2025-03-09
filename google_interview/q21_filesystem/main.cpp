#include <unordered_map>
#include <iostream>
#include <string>

enum permission{
    READ,
    WRITE, // RW
    ADMIN
};

class myFile{
    public:
    myFile()
    {
        m_data = "";
        m_size = 0;
        m_filename = "NO FILE";
    }

    myFile(std::string filename, std::string data, int size){
        m_data = data;
        m_size = size;
        m_filename = filename;
    }

    std::string read()
    {
        return m_data;
    }

    void write(std::string new_data, int size)
    {
        m_data = new_data;
        m_size = size;
    }

    private:
    int m_size;
    std::string m_filename;
    std::string m_data;
};


class User{
    public:
    void add_permission(std::string filename, int permission){
        files[filename] = permission;
    }

    int has_permission(std::string filenmae){
        if(files.find(filenmae) != files.end()){
            return files[filenmae];
        }
        else{
            return -1;
        }
    }
    private:
    std::unordered_map<std::string , int> files;
};

class FS{

    public:

    int upload_file(User &user, std::string filename, std::string data, unsigned int size)
    {
        user.add_permission(filename, WRITE);

        if(files.find(filename) == files.end())
        {
            myFile f(filename,data,size);
            files[filename] = f;
        }
        else
        {
            if(user.has_permission(filename)){
                files[filename].write(data,size);
            }
        }
        return 0;
    }

    int download_file(User &user, std::string filename, myFile &output)
    {
        if(user.has_permission(filename))
        {
            output = files[filename];
            return 0;
        }
        else
        {
            return -1;
        }
    }

    private:

    std::unordered_map<std::string, myFile> files;

};

int main(){
    FS fileSystem;
    User user1;

    std::string filename = "document.txt";
    std::string fileData = "Hello, this is a test file.";

    // Upload a file
    fileSystem.upload_file(user1, filename, fileData, fileData.size());

    // Try to download it
    myFile downloadedFile;
    if (fileSystem.download_file(user1, filename, downloadedFile) == 0) {
        std::cout << "Downloaded file content: " << downloadedFile.read() << std::endl;
    } else {
        std::cout << "Failed to download file. Permission denied." << std::endl;
    }

    return 0;
}