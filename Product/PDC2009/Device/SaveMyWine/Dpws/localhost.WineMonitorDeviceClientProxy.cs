//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     .NET Micro Framework MFSvcUtil.Exe
//     Runtime Version:2.0.00001.0001
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------


using System;
using System.Xml;
using Dpws.Client;
using Dpws.Client.Discovery;
using Dpws.Client.Eventing;
using Dpws.Client.Transport;
using Ws.Services;
using Ws.Services.Utilities;
using Ws.Services.WsaAddressing;
using Ws.Services.Xml;

namespace localhost.WineMonitorDevice
{
    
    
    public class IWineMonitorRequestClientProxy : DpwsClient
    {
        
        public string ServiceEndpoint = null;
        
        private DpwsHttpClient m_httpClient = new DpwsHttpClient();
        
        public IWineMonitorRequestClientProxy()
        {
            Init();
        }
        
        public IWineMonitorRequestClientProxy(int port) : 
                base(port)
        {
            Init();
        }
        
        public virtual void Init()
        {

            // // Set client endpoint address
            EndpointAddress = "urn:uuid:47dc47df-79cb-46e1-8258-9886dee8eaf3";
        }
        
        public virtual GetSensorDataResponse GetSensorData(GetSensorData req)
        {

            // Create request header
            String action;
            action = "http://localhost/WineMonitorDevice/IWineMonitorRequest/GetSensorData";
            WsWsaHeader header;
            header = new WsWsaHeader(action, null, ServiceEndpoint, null, EndpointAddress, null);

            // Create request serializer
            GetSensorDataDataContractSerializer reqDcs;
            reqDcs = new GetSensorDataDataContractSerializer("GetSensorData", "http://localhost/WineMonitorDevice/");

            // Build soap request message
            byte[] soapBuffer = SoapMessageBuilder.BuildSoapMessage(header, reqDcs, req);

            // Send service request
            DpwsSoapResponse response;
            response = m_httpClient.SendRequest(soapBuffer, ServiceEndpoint, false, false);

            // Process response
            GetSensorDataResponseDataContractSerializer respDcs;
            respDcs = new GetSensorDataResponseDataContractSerializer("GetSensorDataResponse", "http://localhost/WineMonitorDevice/");
            GetSensorDataResponse resp;
            resp = ((GetSensorDataResponse)(respDcs.ReadObject(response.Reader)));
            return resp;
        }
    }
}