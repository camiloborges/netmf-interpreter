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
using System.Text;
using System.Xml;
using Dpws.Device;
using Dpws.Device.Services;
using Ws.Services;
using Ws.Services.WsaAddressing;
using Ws.Services.Xml;

namespace localhost.WineMonitorAlert
{
    
    
    public class IWineMonitorAlert : DpwsHostedService
    {
        
        private IIWineMonitorAlert m_service = null;
        
        public IWineMonitorAlert(IIWineMonitorAlert service)
        {
            // Set the service implementation properties
            m_service = service;

            // Set base service properties
            ServiceNamespace = new WsXmlNamespace("iwi", "http://localhost/WineMonitorAlert");
            ServiceID = "urn:uuid:260f9499-5614-49c5-9ffd-287b8b898f4f";
            ServiceTypeName = "IWineMonitorAlert";

            // Add service types here
            ServiceOperations.Add(new WsServiceOperation("http://localhost/WineMonitorAlert/IWineMonitorAlert", "Alert"));

            // Add event sources here
        }
        
        public virtual Byte[] Alert(WsWsaHeader header, XmlReader reader)
        {
            // Build request object
            AlertDataContractSerializer reqDcs;
            reqDcs = new AlertDataContractSerializer("Alert", "http://localhost/WineMonitorAlert");
            Alert req;
            req = ((Alert)(reqDcs.ReadObject(reader)));

            // Create response object
            // Call service operation to process request and return response.
            AlertResponse resp;
            resp = m_service.Alert(req);

            // Create response header
            WsWsaHeader respHeader = new WsWsaHeader("http://localhost/WineMonitorAlert/IWineMonitorAlert/AlertResponse", header.MessageID, WsWellKnownUri.WsaAnonymousUri, null, null, null);

            // Create response serializer
            AlertResponseDataContractSerializer respDcs;
            respDcs = new AlertResponseDataContractSerializer("AlertResponse", "http://localhost/WineMonitorAlert");

            // Build response message and return
            return SoapMessageBuilder.BuildSoapMessage(respHeader, respDcs, resp);
        }
    }
}
