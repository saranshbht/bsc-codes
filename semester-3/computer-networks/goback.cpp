#include<iostream>
//#include<conio>
#include<cmath>
using namespace std;
typedef unsigned int seq_nr;         //sequence or ack numbers
typedef enum{data,ack,nak} frame_kind;   //frame kind definition
typedef enum{frame_arrival,cksum_err,timeout,network_layer_ready} event_type;
int frame_expected=0,frame_to_send=0,ok=1;

int MAX_SEQ,flag=0,err=-1;
int err_con=0;  //specifies whether there is an unacknowledged frame or not
event_type event;

class go_back_n
 {
  public:
	void sender();
	void receiver();
 };

class packet                         //structure of a packet
 { public:
	 char data[5];
 }*p;

class frame                         //structure of a frame
 {public:
  frame_kind kind;       //what kind of a frame is it?
  seq_nr seq;            //sequence number
  seq_nr ack;            //acknowledgemenmt number
  packet * info;           //the network layer packet
 }*s,*r;


void showkind(frame_kind t)
 {  switch(t)
		 { case data : cout<<"data";
							break;
			case ack  : cout<<"ack";
							break;
			case nak  : cout<<"nak";
							break;
		  }
 }

void from_network_layer(packet *i)    //fetch packet from network layer
 {
	 s=new frame;                 //initializing a data frame
	 s->seq=frame_to_send;
	 s->kind=data;
	 s->info=i;
	 frame_to_send=(frame_to_send+1)%(MAX_SEQ+1); //keep the seq nos within range
		cout<<"\n\tConverting packet into frame.....";
 }

void to_physical_layer(frame *s)        //send frame to physical layer
{
  if(event==timeout)
	{ cout<<"\n\tTimeout period expired.Resending frame with seq no "<<err;
	  s->seq=err;
	  frame_to_send=(err+1)%(MAX_SEQ+1);
	  event=frame_arrival;
	}
  else if(s->kind==data)
	{ cout<<"\n\tSending frame to physical layer with following details:";
	  cout<<"\n\t\tKind= ";
	  showkind(s->kind);
	  cout<<", Sequence Number= "<<s->seq;
	}
  else if(ok==1)
	{ cout<<"\n\tSending feedback frame to physical layer : ";
	  cout<<"\n\t\tKind= ";
	  showkind(s->kind);
	  cout<<", Ack= "<<s->ack;
	}
}

void to_network_layer(packet *p)             //deliver packet to network layer
{ cout<<"\n\tSending packet to network layer......";
  cout<<"\n\tData received  ";

  r=new frame;                        //initializing a control frame
  r->kind=ack;
  r->seq=frame_to_send-1;
  r->ack=frame_expected;
  frame_expected=(frame_expected+1)%(MAX_SEQ+1);
}



void from_physical_layer(frame *s)      //fetch frame from physical layer
{ cout<<"\n\tReceived frame from receiver with details : ";
  cout<<"\n\t\tKind= ";
  showkind(s->kind);
  cout<<", Sequence Number= "<<s->seq;
	cout<<"\n\tChecking Sequence number....... ";
	if(frame_expected==s->seq)          //match the seq no with the expected one
	  {  if(s->seq==2 && flag==0)          //for bringing error in a frame
			 { cout<<"\n\tError in received frame ";
				ok=0;
				flag=1;
				err_con=1;
				err=s->seq;
			 }
		 else
		 {
		  cout<<"\n\tSeparating data packet from the frame...........";
		  ok=1;
		  to_network_layer(p);
		 }
	  }
	else
	  { cout<<"\n\n\tFrame not in order.Discarding frame....."; }

}



void go_back_n::sender()
 {  event=frame_arrival;
	  cout<<"\n\n\t\t\t**********Sender Side**********";
	  if(frame_to_send==(err+(MAX_SEQ/2))%(MAX_SEQ+1) && err_con==1 && err>=0)
			{ event=timeout;
			  frame_to_send=err;
			  err_con=0;
			}
	  else if(frame_to_send==MAX_SEQ && frame_to_send!=frame_expected && err_con==1)    //to restart from the last frame having error
				{ from_network_layer(p);
				  frame_to_send=frame_expected;
				  err_con=0;
				}
	  else if(event==frame_arrival)
			{ cout<<"\n\tPutting data in a packet....";
				 p=new packet;
				 cout<<"\n\tPassing data to datalink layer......";
					  from_network_layer(p);
			}
				to_physical_layer(s);
	 receiver();
 }


void go_back_n::receiver()
 {   cout<<"\n\n\t\t\t**********Receiver Side**********";
		 from_physical_layer(s);
		 to_physical_layer(r);
		// getch();
		// clrscr();
		getchar();
		 sender();
 }


int main()
 {
	 int n;
	 cout<<"\n\tEnter the size of window(in bits) : ";
	 cin>>n;
	  MAX_SEQ=pow(2,n)-1;
	 go_back_n ob;
		ob.sender();

		return 0;
 }

