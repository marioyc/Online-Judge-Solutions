class Read4k {
public:
    Read4k(const char* filename) {
        m_fd = open(filename, O_RDONLY);
        assert(m_fd != -1);
    }
    int read4k(char* buffer) {
        return read(m_fd, buffer, 4096);
    }
private:
    int m_fd;
};

class ArbitraryIO {
public:
    ArbitraryIO(Read4k& read4k)
        : m_read4k(read4k) {
            rem = 4096;
        }
    
    int read(int toRead, char* buffer){
        int _toRead = toRead;
        int sz = 4096 - rem;
        int pos = 0;
        
        for(int i = 0;i < min(toRead,sz);++i){
            buffer[pos] = aux[rem];
            ++pos;
            ++rem;
        }
        
        toRead -= min(toRead,sz);
        
        int n = (toRead + 4*1024 - 1) / (4 * 1024);
        
        for(int i = 0;i < n;++i){
            m_read4k.read4k(aux);
            rem = 0;
            
            for(int j = 0;j < min(4 * 1024,toRead);++j){
                buffer[pos] = aux[j];
                ++rem;
                ++pos;
            }
            
            toRead -= 4 * 1024;
        }
        
        return _toRead;
    }
private:
    Read4k& m_read4k;
    char aux[4097]; 
    int rem;
};
