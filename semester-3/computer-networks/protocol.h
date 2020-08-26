#include<iostream>
using namespace std;

typedef unsigned int seq_nr;         //sequence or ack numbers
typedef enum{data,ack,nak} frame_kind;   //frame kind definition
typedef enum{frame_arrival,wait} event_type; //type of event

class packet              //structure of a packet
 { public:
	 char data[5];
 }*p;

class frame              //structure of a frame
 {public:
  frame_kind kind;       //what kind of a frame is it?
  seq_nr seq;            //sequence number
  seq_nr ack;            //acknowledgemenmt number
  packet * info;         //the network layer packet
 }*s,*r;

int a=-1,q=-1;

int wait_for_event(event_type event)  //wait for an event to happen;return its type in event
{ if(event==frame_arrival)
	  { return 1 ;}
  else return 0;
}

void showkind(frame_kind t)         //display the event type
 {  switch(t)
		 { case data : cout<<"data";
							break;
			case ack  : cout<<"ack";
							break;
			case nak  : cout<<"nak";
							break;
		  }
 }

void from_network_layer(packet *i)      //fetch packet from network layer
 {  	s=new frame;
	 cout<<"\n\tConverting packet into frame.....";
	  s->seq=++a;
	  s->kind=data;
	  s->info=i;
 }

void to_physical_layer(frame *s)       //tranfer frame to physical layer
{
  if(s->kind==data)
	{ cout<<"\n\tSending frame to physical layer with following details:";
	  cout<<"\n\t\tKind= ";
	  showkind(s->kind);
	  cout<<", Sequence Number= "<<s->seq;
	  cout<<"\n\t\tData= ";
			for(int i=0;i<5;i++)
			 { cout<<s->info->data[i];}
	}
  else
	{ cout<<"\n\tSending feedback frame to physical layer : ";
	  cout<<"\n\t\tKind= ";
	  showkind(s->kind);
	  cout<<", Ack= "<<s->ack;
	}
}

void from_physical_layer(frame *s)      //fetch frame from physical layer
{ cout<<"\n\tReceived frame from receiver with details : ";
  cout<<"\n\t\tKind= ";
  showkind(s->kind);
  cout<<", Sequence Number= "<<s->seq;
  cout<<"\n\t\tData= ";
	for(int i=0;i<5;i++)
	  { cout<<s->info->data[i];}
	cout<<"\n\tChecking Sequence number....... ";
	if(q!=s->seq)
	  {cout<<"\n\tSeparating data packet from the frame...........";}
	else
	  { cout<<"\n\tDuplicate frame identified....\n\tDiscarding frame.....";}
}

void to_network_layer(packet *p)        //transfer packet to network layer
{ cout<<"\n\tSending packet to network layer......";
  q=s->seq;
  cout<<"\n\tData received : ";
	 for(int i=0;i<5;i++)
	  { cout<<p->data[i];}
  r=new frame;
  r->kind=ack;
  r->seq=0;
  r->ack=s->seq;
}



