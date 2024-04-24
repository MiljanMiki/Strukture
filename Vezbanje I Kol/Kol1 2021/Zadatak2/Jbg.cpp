

unsigned int h(char* key)
{
    return f(g(key))
}

unsigned int g(char* key)
{
    unsigned int b1=(unsigned int)key[0]*100+(unsigned int)key[1]*10+(unsigned int)key[2];
    unsigned int b2=(unsigned int)key[3]*100+(unsigned int)key[4]*10+(unsigned int)key[5];

    return b1+b2;
}
unsigned int f(unsigned int key)
{
    return k%m;
}

Pok* pomocnaMetoda(char* key)
{
    if(count==m)
        throw "\n********Tablica je puna!!**********\n";

    int probe=h(key);
    if(array[probe]!=2)
        throw "\n*******Trazeni element ne postoji u tablici!**********\n";

    int prev=-1;
    while(array[probe].next!=-1 && array[probe].status==2)
    {
        prev=probe;
        probe=array[probe].next;
    }
    if(prev==-1) //znaci da nema sinonimski
        return null;
        

    Pok* p = array[probe].info;
    array[probe].status=1;//obrisan
    array[probe]=null;//ili se poziva destruktor ili je to =DefaultConstructor() ili deleteRecord ili sta vec...
    array[prev].next=-1;


}