#include<bits/stdc++.h>
using namespace std;

void itineararyTickets(unordered_map<string,string>ticket){
    unordered_set<string> to;
    for(pair<string,string> tickets:ticket){
        to.insert(tickets.second);
    }
    string start ="";
    for(pair<string,string> tickets:ticket){
        if(to.find(tickets.first) == to.end()){

            start =tickets.first;

        }
    }

    cout<<start<<"->";
    while(ticket.count(start)){
        cout<<ticket[start]<<"->";
        start=ticket[start];

    }

}

int main(){
    unordered_map<string,string>ticket;
    ticket["Chennai"] = "Bengaluru";
    ticket["Mumbai"] = "Delhi";
    ticket["Goa"] = "Chennai";
    ticket["Delhi"] = "Goa";
    itineararyTickets(ticket);
    return 0;
}