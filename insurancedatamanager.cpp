
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>
#include <cstdlib>
#include<string>
#include<iomanip>
#include<ctime>
using namespace std;
class date
{
public:
    int day;
    int month;
    int year;
    bool operator==(date);
};
bool date::operator==(date x)
{
    if(x.day==day&&x.month==month&&x.year==year)
        return 1;
    else
        return 0;
}
struct node
{
    int id;
    int sa;
    int term;
    char mode;
    int premium;
    date doc;
    date dom;
    long int ret;
    struct node *next;
}*front=NULL,*rear=NULL,*temp;
struct data
{
    int cid;
    string name;
    int age;
    int c;
    struct node *front;
    struct node *rear;
};
struct BTreeNode
{
    struct data d[5];
    BTreeNode **child_ptr;
    bool leaf;
    int n;
}*root = NULL, *np = NULL, *x = NULL;
BTreeNode * init()
{
    int i;
    np = new BTreeNode;
    np->child_ptr = new BTreeNode *[6];
    np->leaf = true;
    np->n = 0;
    for (i = 0; i < 6; i++)
    {
        np->d[i].c=0;
        np->d[i].age=0;
        np->child_ptr[i] = NULL;
    }
    return np;
}
int counter=0;
void dispc(BTreeNode *p,int x)
{
   cout<<endl;
    int i;
        if(p==NULL&&p==root)
        {
            cout<<"No Data!"<<endl;
            return;
        }
        for (i = 0; i < p->n; i++)
        {
            if (p->leaf == false)
            {
                if(p->child_ptr[i]!=NULL)
                    dispc(p->child_ptr[i],x);
            }
            if(p->d[i].cid==x)
            {
                temp=p->d[i].front;
                cout <<"Client ID: "<< p->d[i].cid<<endl;
                cout <<"Client name: "<<p->d[i].name<<endl<<endl;
                cout <<"Client age: "<<p->d[i].age<<endl;
                while(temp!=NULL)
                {
                    cout <<"Policy ID: "<< temp->id<<endl;
                    cout <<"Sum Assured: "<<temp->sa<<endl;
                    cout <<"Term: "<<temp->id<<endl;
                    cout <<"Mode of payment: ";
                    if(temp->mode=='Y'||temp->mode=='y')
                    cout<<"Yearly"<<endl;
                    else if(temp->mode=='M'||temp->mode=='m')
                    cout<<"Monthly"<<endl;
                    else if(temp->mode=='Q'||temp->mode=='q')
                    cout<<"Quarterly"<<endl;
                    else if(temp->mode=='H'||temp->mode=='h')
                    cout<<"Half Yearly"<<endl;
                    cout <<"Premium: "<<temp->premium<<endl;
                    cout <<"Date of commencement: "<<temp->doc.day<<"/"<<temp->doc.month<<"/"<<temp->doc.year<<endl;
                    cout <<"Date of maturity: "<<temp->dom.day<<"/"<<temp->dom.month<<"/"<<temp->dom.year<<endl;
                    cout <<"Return: "<<temp->ret<<"\n"<<endl;
                    temp=temp->next;
                }
                return;
            }
        }
    cout<<"Client not found!"<<endl;
    cout<<endl;
}
void dispall(BTreeNode *p)
{
   cout<<endl;
    int i;
        if(p==NULL&&p==root)
        {
            cout<<"No Data!"<<endl;
            return;
        }
        for (i = 0; i < p->n; i++)
        {
            if (p->leaf == false)
            {
                if(p->child_ptr[i]!=NULL)
                    dispall(p->child_ptr[i]);
            }
            temp=p->d[i].front;
            cout <<"Client ID: "<< p->d[i].cid<<endl;
                cout <<"Client name: "<<p->d[i].name<<endl<<endl;
                cout <<"Client age: "<<p->d[i].age<<endl;
                while(temp!=NULL)
                {
                    cout <<"Policy ID: "<< temp->id<<endl;
                    cout <<"Sum Assured: "<<temp->sa<<endl;
                    cout <<"Term: "<<temp->id<<endl;
                    cout <<"Mode of payment: ";
                    if(temp->mode=='Y'||temp->mode=='y')
                    cout<<"Yearly"<<endl;
                    else if(temp->mode=='M'||temp->mode=='m')
                    cout<<"Monthly"<<endl;
                    else if(temp->mode=='Q'||temp->mode=='q')
                    cout<<"Quarterly"<<endl;
                    else if(temp->mode=='H'||temp->mode=='h')
                    cout<<"Half Yearly"<<endl;
                    cout <<"Premium: "<<temp->premium<<endl;
                    cout <<"Date of commencement: "<<temp->doc.day<<"/"<<temp->doc.month<<"/"<<temp->doc.year<<endl;
                    cout <<"Date of maturity: "<<temp->dom.day<<"/"<<temp->dom.month<<"/"<<temp->dom.year<<endl;
                    cout <<"Return: "<<temp->ret<<"\n"<<endl;
                    temp=temp->next;
                }
        }
    cout<<endl;
}
void dispol(BTreeNode *p,int x)
{
    cout<<endl;
    int i;
    if(p==NULL&&p==root)
    {
        cout<<"No Data!"<<endl;
        return;
    }
    for (i = 0; i < p->n; i++)
    {
        if (p->leaf == false)
        {
            if(p->child_ptr[i]!=NULL)
                dispol(p->child_ptr[i],x);
        }
        temp=p->d[i].front;
        while(temp!=NULL)
        {
            if(temp->id==x)
            {
                cout <<"Client ID: "<< p->d[i].cid<<endl;
                cout <<"Client name: "<<p->d[i].name<<endl;
                cout <<"Client age: "<<p->d[i].age<<endl;
                cout <<"Policy ID: "<< temp->id<<endl;
                cout <<"Sum Assured: "<<temp->sa<<endl;
                cout <<"Term: "<<temp->id<<endl;
                cout <<"Mode of payment: ";
                if(temp->mode=='Y'||temp->mode=='y')
                    cout<<"Yearly"<<endl;
                else if(temp->mode=='M'||temp->mode=='m')
                    cout<<"Monthly"<<endl;
                else if(temp->mode=='Q'||temp->mode=='q')
                    cout<<"Quarterly"<<endl;
                else if(temp->mode=='H'||temp->mode=='h')
                    cout<<"Half Yearly"<<endl;
                cout <<"Premium: "<<temp->premium<<endl;
                cout <<"Date of commencement: "<<temp->doc.day<<"/"<<temp->doc.month<<"/"<<temp->doc.year<<endl;
                cout <<"Date of maturity: "<<temp->dom.day<<"/"<<temp->dom.month<<"/"<<temp->dom.year<<endl;
                cout <<"Return: "<<temp->ret<<endl;
                return;
            }
            else
            {
                temp=temp->next;
            }
        }
    }
    cout<<"Policy not found!"<<endl;
    cout<<endl;
}
void delc(BTreeNode *p,int x)
{
    cout<<endl;
    int i;
    if(p==NULL&&p==root)
    {
        cout<<"No Data!"<<endl;
        return;
    }
    for (i = 0; i < p->n; i++)
    {
        if (p->leaf == false)
        {
            if(p->child_ptr[i]!=NULL)
                delc(p->child_ptr[i],x);
        }
        if(p->d[i].cid==x)
        {
            p->d[i]=p->d[i+1];
            cout<<"Deleted Successfully!";
            return;
        }
    }
    cout<<"Client not found!"<<endl;
    cout<<endl;
}
bool compc(BTreeNode *p,int x)
{
    node *temp2,*previous;
    int i;
    if(p==NULL&&p==root)
    {
        cout<<"No Data!"<<endl;
        return 0;
    }
    for(i=0; i<=p->n; i++)
    {
        if (p->leaf == false)
        {
            if(p->child_ptr[i]!=NULL)
                compc(p->child_ptr[i],x);
        }
        temp=p->d[i].front;
        while(temp!=NULL)
        {
            if(p->d[i].front->id==x)
            {
                p->d[i].front=p->d[i].front->next;
                cout<<"Policy already present!"<<endl;
                return 0;
            }
            else if(temp->id==x)
            {
                previous->next=temp->next;
                temp->next=p->d[i].front;
                p->d[i].front=temp;
                p->d[i].front=p->d[i].front->next;
                cout<<"Policy already present"<<endl;
                return 0;
            }
            else
            {
                previous=temp;
                temp=temp->next;
            }
        }
    }
    return 1;
}
void delpol(BTreeNode *p,int x)
{
    node *temp2,*previous;
    int i;
    if(p==NULL&&p==root)
    {
        cout<<"No Data!"<<endl;
        return;
    }
    for(i=0; i<=p->n; i++)
    {
        if (p->leaf == false)
        {
            if(p->child_ptr[i]!=NULL)
                delpol(p->child_ptr[i],x);
        }
        temp=p->d[i].front;
        while(temp!=NULL)
        {
            if(p->d[i].front->id==x)
            {
                p->d[i].front=p->d[i].front->next;
                cout<<"Policy deleted successfully!"<<endl;
                counter--;
                return;
            }
            else if(temp->id==x)
            {
                previous->next=temp->next;
                temp->next=p->d[i].front;
                p->d[i].front=temp;
                p->d[i].front=p->d[i].front->next;
                cout<<"Policy deleted successfully!"<<endl;
                counter--;
                return;
            }
            else
            {
                previous=temp;
                temp=temp->next;
            }
        }
    }
    cout<<"Policy not found!"<<endl;
}
void sort(struct data *p, int n)
{
    int i, j;
    struct data temp;
    for (i = 0; i < n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (p[i].cid > p[j].cid)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}
struct data split_child(BTreeNode *x, int i)
{
    int j;
    struct data mid;
    BTreeNode *np1, *np3, *y;
    np3 = init();
    np3->leaf = true;
    if (i == -1)
    {
        mid = x->d[2];
        x->d[2].cid = 0;
        x->d[2].front = NULL;
        x->d[2].rear = NULL;
        x->n--;
        np1 = init();
        np1->leaf = false;
        x->leaf = true;
        for (j = 3; j < 5; j++)
        {
            np3->d[j - 3] = x->d[j];
            np3->child_ptr[j - 3] = x->child_ptr[j];
            np3->n++;
            x->d[j].cid = 0;
            x->d[j].front = NULL;
            x->d[j].rear = NULL;
            x->n--;
        }
        for(j = 0; j < 6; j++)
        {
            x->child_ptr[j] = NULL;
        }
        np1->d[0] = mid;
        np1->child_ptr[np1->n] = x;
        np1->child_ptr[np1->n + 1] = np3;
        np1->n++;
        root = np1;
    }
    else
    {
        y = x->child_ptr[i];
        mid = y->d[2];
        y->d[2].cid = 0;
        y->d[2].front = NULL;
        y->d[2].rear = NULL;
        y->n--;
        for (j = 3; j < 5; j++)
        {
            np3->d[j - 3] = y->d[j];
            np3->n++;
            y->d[j].cid = 0;
            y->d[j].front = NULL;
            y->d[j].rear = NULL;
            y->n--;
        }
        x->child_ptr[i + 1] = y;
        x->child_ptr[i + 1] = np3;
    }
    return mid;
}
void insert(int y,string name,node * a,int age)
{
    int i=0;
    struct data temp;
    x = root;
    if (x == NULL)
    {
        root = init();
        x = root;
    }
    else
    {
        if (x->leaf == true && x->n == 5)
        {
            temp = split_child(x, -1);
            x = root;
            for (i = 0; i < (x->n); i++)
            {
                if ((y > x->d[i].cid) && (y < x->d[i + 1].cid))
                {
                    i++;
                    break;
                }
                else if (y==x->d[i].cid)
                {
                    break;
                }
                else if (y < x->d[0].cid)
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
            if (y!=x->d[i].cid)
            {
                x = x->child_ptr[i];
            }
        }
        else
        {
            while (x->leaf == false)
            {
                for (i = 0; i < (x->n); i++)
                {
                    if ((y > x->d[i].cid) && (y < x->d[i + 1].cid))
                    {
                        i++;
                        break;
                    }
                    else if (y==x->d[i].cid)
                    {
                        break;
                    }
                    else if (y < x->d[0].cid)
                    {
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
                if ((x->child_ptr[i])->n == 5)
                {
                    temp = split_child(x, i);
                    x->d[x->n] = temp;
                    x->n++;
                    continue;
                }
                else if(y!=x->d[i].cid)
                {
                    x = x->child_ptr[i];
                }
                else
                {
                    break;
                }
            }
        }
    }
    if(x->d[i].cid==y)
    {
        x->d[i].rear->next=a;
        x->d[i].rear=a;
        cout<<"Data stored securely!"<<endl;
        x->d[i].c++;
        return;
    }
    x->d[x->n].cid = y;
    x->d[x->n].name=name;
    x->d[x->n].age=age;
    x->d[x->n].front=a;
    x->d[x->n].rear=a;
    sort(x->d, x->n);
    cout<<"Data stored securely!"<<endl;
    x->n++;
}
void check(BTreeNode* p)
{
    int d,m,y;
    time_t now=time(0);
    tm *ltm=localtime(&now);
    d=ltm->tm_mday;
    m=ltm->tm_mon+1;
    y=ltm->tm_year+1900;
    node *temp2,*previous;
    int i;
    if(p==NULL&&p==root)
    {
        cout<<"No Data!"<<endl;
        return;
    }
    for(i=0; i<=p->n; i++)
    {
        if (p->leaf == false)
        {
            if(p->child_ptr[i]!=NULL)
                check(p->child_ptr[i]);
        }
        temp=p->d[i].front;
        while(temp!=NULL)
        {
            if(p->d[i].front->dom.day==d&&p->d[i].front->dom.month==m&&p->d[i].front->dom.year==y)
            {
                cout <<"\tClient ID: "<< p->d[i].cid<<endl;
                cout <<"\tClient name: "<<p->d[i].name<<endl;
                cout <<"\tClient age: "<<p->d[i].age<<endl;
                cout <<"\tPolicy ID: "<<p->d[i].front->id<<endl;
                cout <<"\tSum Assured: "<<p->d[i].front->sa<<endl;
                cout <<"\tTerm: "<<p->d[i].front->id<<endl;
                cout <<"\tMode of payment: ";
                if(p->d[i].front->mode=='Y'||p->d[i].front->mode=='y')
                    cout<<"Yearly"<<endl;
                else if(p->d[i].front->mode=='M'||p->d[i].front->mode=='m')
                    cout<<"Monthly"<<endl;
                else if(p->d[i].front->mode=='Q'||p->d[i].front->mode=='q')
                    cout<<"Quarterly"<<endl;
                else if(p->d[i].front->mode=='H'||p->d[i].front->mode=='h')
                    cout<<"Half Yearly"<<endl;
                cout <<"\tPremium: "<<p->d[i].front->premium<<endl;
                cout <<"\tDate of commencement: "<<p->d[i].front->doc.day<<"/"<<p->d[i].front->doc.month<<"/"<<p->d[i].front->doc.year<<endl;
                cout <<"\tDate of maturity: "<<p->d[i].front->dom.day<<"/"<<p->d[i].front->dom.month<<"/"<<p->d[i].front->dom.year<<endl;
                cout <<"\tReturn: "<<p->d[i].front->ret<<endl;
                p->d[i].front=p->d[i].front->next;
                counter--;
                return;
            }
            else if(temp->dom.day==d&&temp->dom.month==m&&temp->dom.year==y)
            {
                cout <<"\tClient ID: "<< p->d[i].cid<<endl;
                cout <<"\tClient name: "<<p->d[i].name<<endl;
                cout <<"\tClient age: "<<p->d[i].age<<endl;
                cout <<"\tPolicy ID: "<< temp->id<<endl;
                cout <<"\tSum Assured: "<<temp->sa<<endl;
                cout <<"\tTerm: "<<temp->id<<endl;
                cout <<"\tMode of payment: ";
                if(temp->mode=='Y'||temp->mode=='y')
                    cout<<"Yearly"<<endl;
                else if(temp->mode=='M'||temp->mode=='m')
                    cout<<"Monthly"<<endl;
                else if(temp->mode=='Q'||temp->mode=='q')
                    cout<<"Quarterly"<<endl;
                else if(temp->mode=='H'||temp->mode=='h')
                    cout<<"Half Yearly"<<endl;
                cout <<"\tPremium: "<<temp->premium<<endl;
                cout <<"\tDate of commencement: "<<temp->doc.day<<"/"<<temp->doc.month<<"/"<<temp->doc.year<<endl;
                cout <<"\tDate of maturity: "<<temp->dom.day<<"/"<<temp->dom.month<<"/"<<temp->dom.year<<endl;
                cout <<"\tReturn: "<<temp->ret<<endl;
                previous->next=temp->next;
                temp->next=p->d[i].front;
                p->d[i].front=temp;
                p->d[i].front=p->d[i].front->next;
                cout<<"Policy deleted successfully!"<<endl;
                counter--;
                return;
            }
            else
            {
                previous=temp;
                temp=temp->next;
            }
        }
    }
}

main()
{
    int i,x, n,t,age,choice,l;
    float pre;
    time_t now=time(0);
    tm *ltm=localtime(&now);
    char c;
    string name;
    cout<<"\t\tInsurance Policy handling application"<<endl;
    while(1)
    {
        cout<<endl<<"\t The list of policies matured:"<<endl;
        check(root);
        cout<<endl;
        cout<<"*******************************************************************************"<<endl;
        cout<<"\tChoose one of the options from following:"<<endl;
        cout<<"\t1. Insert new policy\n";
        cout<<"\t2. Delete any policy\n";
        cout<<"\t3. Delete client\n";
        cout<<"\t4. Display policy\n";
        cout<<"\t5. Display client with policies\n";
        cout<<"\t6. Total number of policies\n";
        cout<<"\t7. Premium calculator\n";
        cout<<"\t8. Display all the policies\n";
        cout<<"\t9. exit\n";
        cout<<"*******************************************************************************"<<endl;
        cout<<"\tEnter your option: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            temp = new(struct node);
            cout<<"Client Id: ";
            cin>>t;
            cout<<"Name: ";
            cin>>name;
            cout<<"Policy Id: ";
            cin>>temp->id;
            /*if(compc(root,temp->id)==0)
            {
                compc(root,temp->id);
                break;
            }*/
            cout<<"Age: ";
            cin>>age;
            cout<<"Sum Assured: ";
            cin>>temp->sa;
            cout<<"Term: ";
            cin>>temp->term;
            cout<<"Choose the Mode: "<<endl;
            cout<<"M-Monthly"<<endl;
            cout<<"Y-Yearly"<<endl;
            cout<<"H-Half yearly"<<endl;
            cout<<"Q-Quarterly"<<endl;
            cout<<"Enter the mode: ";
            cin>>temp->mode;
            if(temp->mode=='Y'||temp->mode=='y')
                temp->premium=temp->sa/temp->term;
            else if(temp->mode=='M'||temp->mode=='m')
                temp->premium=temp->sa/(temp->term*12);
            else if(temp->mode=='Q'||temp->mode=='q')
                temp->premium=temp->sa/(temp->term*3);
            else if(temp->mode=='H'||temp->mode=='h')
                temp->premium=temp->sa/(temp->term*2);
label1:
            cout<<"Date of Commencement (Enter date with spaces): ";
            cin>>temp->doc.day>>temp->doc.month>>temp->doc.year;
            cout<<"Date of Maturity (Enter date with spaces): ";
            cin>>temp->dom.day>>temp->dom.month>>temp->dom.year;
            if(temp->dom==temp->doc)
            {
                cout<<"Date of commencement and date of maturity cannot be same!"<<endl;
                goto label1;
            }
            temp->ret=temp->sa*(1.2);
            insert(t,name,temp,age);
            counter++;
            break;
        }
        case 2:
        {
            cout<<"Enter the policy id: ";
            cin>>x;
            delpol(root,x);
            break;
        }
        case 3:
        {
            cout<<"Enter the name of client: ";
            cin>>l;
            delc(root,l);
            break;
        }
        case 4:
        {
            cout<<"Enter the policy ID: ";
            cin>>x;
            dispol(root,x);
            break;
        }
        case 5:
        {
            cout<<"Enter the client ID: ";
            cin>>l;
            dispc(root,l);
            break;
        }
        case 6:
        {
            cout<<"Total number of policies: "<<counter<<endl;
            break;
        }
        case 7:
            {
                cout<<"Enter the sum assured: ";
                cin>>n;
                cout<<"Enter the mode: ";
                cin>>c;
                cout<<"Term: ";
                cin>>t;
                if(c=='Y'||c=='y')
                    pre=n/t;
                else if(c=='M'||c=='m')
                    pre=n/(t*12);
                else if(c=='Q'||c=='q')
                    pre=n/t*4;
                else if(c=='H'||c=='h')
                    pre=n/(t*2);
                cout<<"Premium: "<<fixed<<setprecision(2)<<pre<<endl;
                break;
            }
        case 8:
            {
                dispall(root);
                break;
            }
        case 9:
        {
            cout<<"Press 1 to exit: ";
            cin>>x;
            if(x==1)
                exit(1);
            break;
        }
        default:
        {
            cout<<"Please enter the correct number!"<<endl;
            break;
        }
        }
    }
}
