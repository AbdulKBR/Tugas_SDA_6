#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;

struct TNode{
    int data;
    TNode *next;
};TNode *head, *tail,*depan,*belakang;

void init(){
    head=NULL;
    tail=NULL;
    depan=NULL;
    belakang=NULL;
}

int isEmpty(){
    if(tail==NULL){
    return 1;
    }else{
        return 0;
    }
}
void insertDepan(int databaru)
{
    TNode *baru;
    baru =new TNode;
    baru->data=databaru;
    baru->next=NULL;
    if(isEmpty()==1)
    {
        head=tail=baru;
        tail->next=NULL;
    }else{
        baru->next=head;
        head=baru;
    }
    cout<<"Input berhasil";
}

void insertBelakang(int data){
    TNode *baru;
    baru=new TNode;
    baru->data=data;
    baru->next=NULL;
    if(isEmpty()==1){
        head=baru;
        tail=baru;
        tail->next=NULL;
    }else
    {
        tail->next=baru;
        tail=baru;
    }
    cout<<"\n Input berhasil"<<endl;
}
void hapusDepan(){
    TNode *hapus;
    int d;
    if(isEmpty()==0){
        if(depan!=belakang){
            hapus=depan;
            d=hapus->data;
            depan=depan->next;
            delete hapus;
        }else{
            d=belakang->data;
            depan=belakang=NULL;
        }
        cout<<d<<"Terhapus";
    }else cout<<"Masih kosong\n";
}
void hapusBelakang(){
    TNode *bantu,*hapus;
    int d;
    if(isEmpty()==0){
        bantu=depan;
        if(depan!=belakang){
            while(bantu->next!=belakang){
                bantu=bantu->next;
            }
            hapus=belakang;
            belakang=bantu;
            d=hapus->data;
            delete hapus;
            belakang->next=NULL;
        }else{
            d=belakang->data;
            depan=belakang=NULL;
        }
        cout<<d<<"Terhapus\n";
    }else cout<<"Masih kosong\n";
}
void tampil(){
    TNode *bantu;
    bantu=head;
    if(isEmpty()==0){
        cout<<"depan :";
         while(bantu!=NULL){
            cout<<bantu->data<<"->";
            bantu=bantu->next;
        }
    }else if(isEmpty()==0){
        cout<<"belakang :";
        while(bantu!=NULL){
            cout<<bantu->data<<"->";
            bantu=bantu->next;
        }
     cout<<"\n Data masih kosong"<<endl;
    }
}
main(){
    int pil,data,databaru;
    init();
    do{
        system("cls");
        cout<<endl;
        cout<<"link list insert"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"1. insert depan"<<endl;
        cout<<"2. insert belakang"<<endl;
        cout<<"3. delete depan"<<endl;
        cout<<"4. delete belakang"<<endl;
        cout<<"5. tampilkan data"<<endl;
        cout<<"0. keluar"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"masukkan pilihan :";cin>>pil;
        switch(pil){
            case 1: system("cls");{
                cout<<"\nInsert Depan"<<endl;
                cout<<"-------------"<<endl;
                cout<<"masukkan data : ";cin>>databaru;
                insertDepan(databaru);
                break;
            }
            case 2: system("cls");{
                cout<<"\nInsert Belakang"<<endl;
                cout<<"-------------"<<endl;
                cout<<"masukkan data : ";cin>>data;
                insertBelakang(data);
                break;
            }
            case 3: system("cls");{
                cout<<"\ndata depan terhapus"<<endl;
                hapusDepan();
                break;
            }
            case 4: system("cls");{
                cout<<"\nData Belakang terhapus"<<endl;
                hapusBelakang();
                break;
            }
            case 5: system("cls");{
                cout<<"Tampilkan data"<<endl;
                cout<<"-------------"<<endl;
                tampil();
                break;
            }
            case 0 : system("cls");{
                return 0;
                break;
            }default:
            system ("cls");{
                cout<<"pilihan tidak tersedia"<<endl;
            }
        }getch();
    }while(pil!=7);
}
