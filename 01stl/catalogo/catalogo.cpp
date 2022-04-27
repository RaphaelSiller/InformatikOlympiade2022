typedef
struct catalogo_s
{
    long long idOfBook;
    int conta;
} catalogo_t;

static catalogo_t library[200000];
static int nIDs = 0; //how many different IDs there are

void aggiungi(long long int id) {
    bool isNewBook = true;
    //find ID
    for (int i = 0; i <= nIDs; i++)
    {
        if (library[i].idOfBook == id)
        {
            library[i].conta++;
            isNewBook = false;
            i = nIDs+1;
        }
    }
    
    if(isNewBook) {
        library[nIDs].idOfBook = id;
        library[nIDs].conta++;
        nIDs++;
    }

    
}

void togli(long long int id) {
    for (int i = 0; i < nIDs; i++) {
        if (id == library[i].idOfBook){
            library[i].conta--;
            if (library[i].conta < 0) {
                library[i].idOfBook = -1;
            }
        }
        
    }
    
}

int conta(long long int id) {
    int ret = 0;
    for (int i = 0; i < nIDs; i++) {
        if (id == library[i].idOfBook){
            ret = library[i].conta;
        }
    }
    return ret;
}

