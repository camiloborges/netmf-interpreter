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
using System.Ext;
using System.Ext.Xml;
using Ws.ServiceModel;
using Ws.Services.Mtom;
using Ws.Services.Serialization;
using XmlElement = Ws.Services.Xml.WsXmlNode;
using XmlAttribute = Ws.Services.Xml.WsXmlAttribute;
using XmlConvert = Ws.Services.Serialization.WsXmlConvert;

namespace localhost.WineMonitorService
{
    
    
    [DataContract(Namespace="http://localhost/WineMonitorService/")]
    public class RegisterWineCabinet
    {
        
        [DataMember(Order=0, IsNillable=true, IsRequired=false)]
        public string cabinetId;
        
        [DataMember(Order=1, IsNillable=true, IsRequired=false)]
        public string endpointConfigName;
        
        [DataMember(Order=2, IsNillable=true, IsRequired=false)]
        public string endpointAddress;
    }
    
    public class RegisterWineCabinetDataContractSerializer : DataContractSerializer
    {
        
        public RegisterWineCabinetDataContractSerializer(string rootName, string rootNameSpace) : 
                base(rootName, rootNameSpace)
        {
        }
        
        public RegisterWineCabinetDataContractSerializer(string rootName, string rootNameSpace, string localNameSpace) : 
                base(rootName, rootNameSpace, localNameSpace)
        {
        }
        
        public override object ReadObject(XmlReader reader)
        {
            RegisterWineCabinet RegisterWineCabinetField = null;
            if (IsParentStartElement(reader, false, true))
            {
                RegisterWineCabinetField = new RegisterWineCabinet();
                reader.Read();
                if (IsChildStartElement(reader, "cabinetId", true, false))
                {
                    reader.Read();
                    RegisterWineCabinetField.cabinetId = reader.ReadString();
                    reader.ReadEndElement();
                }
                if (IsChildStartElement(reader, "endpointConfigName", true, false))
                {
                    reader.Read();
                    RegisterWineCabinetField.endpointConfigName = reader.ReadString();
                    reader.ReadEndElement();
                }
                if (IsChildStartElement(reader, "endpointAddress", true, false))
                {
                    reader.Read();
                    RegisterWineCabinetField.endpointAddress = reader.ReadString();
                    reader.ReadEndElement();
                }
                reader.ReadEndElement();
            }
            return RegisterWineCabinetField;
        }
        
        public override void WriteObject(XmlWriter writer, object graph)
        {
            RegisterWineCabinet RegisterWineCabinetField = ((RegisterWineCabinet)(graph));
            if (WriteParentElement(writer, true, true, graph))
            {
                if (WriteChildElement(writer, "cabinetId", true, false, RegisterWineCabinetField.cabinetId))
                {
                    writer.WriteString(RegisterWineCabinetField.cabinetId);
                    writer.WriteEndElement();
                }
                if (WriteChildElement(writer, "endpointConfigName", true, false, RegisterWineCabinetField.endpointConfigName))
                {
                    writer.WriteString(RegisterWineCabinetField.endpointConfigName);
                    writer.WriteEndElement();
                }
                if (WriteChildElement(writer, "endpointAddress", true, false, RegisterWineCabinetField.endpointAddress))
                {
                    writer.WriteString(RegisterWineCabinetField.endpointAddress);
                    writer.WriteEndElement();
                }
                writer.WriteEndElement();
            }
            return;
        }
    }
    
    [DataContract(Namespace="http://localhost/WineMonitorService/")]
    public class RegisterWineCabinetResponse
    {
    }
    
    public class RegisterWineCabinetResponseDataContractSerializer : DataContractSerializer
    {
        
        public RegisterWineCabinetResponseDataContractSerializer(string rootName, string rootNameSpace) : 
                base(rootName, rootNameSpace)
        {
        }
        
        public RegisterWineCabinetResponseDataContractSerializer(string rootName, string rootNameSpace, string localNameSpace) : 
                base(rootName, rootNameSpace, localNameSpace)
        {
        }
        
        public override object ReadObject(XmlReader reader)
        {
            RegisterWineCabinetResponse RegisterWineCabinetResponseField = null;
            if (IsParentStartElement(reader, false, true))
            {
                RegisterWineCabinetResponseField = new RegisterWineCabinetResponse();
                reader.Read();
                reader.ReadEndElement();
            }
            return RegisterWineCabinetResponseField;
        }
        
        public override void WriteObject(XmlWriter writer, object graph)
        {
            RegisterWineCabinetResponse RegisterWineCabinetResponseField = ((RegisterWineCabinetResponse)(graph));
            if (WriteParentElement(writer, true, true, graph))
            {
                writer.WriteEndElement();
            }
            return;
        }
    }
    
    [DataContract(Namespace="http://localhost/WineMonitorService/")]
    public class UpdateSensorData
    {
        
        [DataMember(Order=0, IsNillable=true, IsRequired=false)]
        public string cabinetId;
        
        [DataMember(Order=1, IsNillable=true, IsRequired=false)]
        public schemas.datacontract.org.WineMonitorService.WineSensorData data;
    }
    
    public class UpdateSensorDataDataContractSerializer : DataContractSerializer
    {
        
        public UpdateSensorDataDataContractSerializer(string rootName, string rootNameSpace) : 
                base(rootName, rootNameSpace)
        {
        }
        
        public UpdateSensorDataDataContractSerializer(string rootName, string rootNameSpace, string localNameSpace) : 
                base(rootName, rootNameSpace, localNameSpace)
        {
        }
        
        public override object ReadObject(XmlReader reader)
        {
            UpdateSensorData UpdateSensorDataField = null;
            if (IsParentStartElement(reader, false, true))
            {
                UpdateSensorDataField = new UpdateSensorData();
                reader.Read();
                if (IsChildStartElement(reader, "cabinetId", true, false))
                {
                    reader.Read();
                    UpdateSensorDataField.cabinetId = reader.ReadString();
                    reader.ReadEndElement();
                }
                schemas.datacontract.org.WineMonitorService.WineSensorDataDataContractSerializer dataDCS = new schemas.datacontract.org.WineMonitorService.WineSensorDataDataContractSerializer("data", "http://localhost/WineMonitorService/", "http://schemas.datacontract.org/2004/07/WineMonitorService");
                UpdateSensorDataField.data = ((schemas.datacontract.org.WineMonitorService.WineSensorData)(dataDCS.ReadObject(reader)));
                reader.ReadEndElement();
            }
            return UpdateSensorDataField;
        }
        
        public override void WriteObject(XmlWriter writer, object graph)
        {
            UpdateSensorData UpdateSensorDataField = ((UpdateSensorData)(graph));
            if (WriteParentElement(writer, true, true, graph))
            {
                if (WriteChildElement(writer, "cabinetId", true, false, UpdateSensorDataField.cabinetId))
                {
                    writer.WriteString(UpdateSensorDataField.cabinetId);
                    writer.WriteEndElement();
                }
                schemas.datacontract.org.WineMonitorService.WineSensorDataDataContractSerializer dataDCS = new schemas.datacontract.org.WineMonitorService.WineSensorDataDataContractSerializer("data", "http://localhost/WineMonitorService/", "http://schemas.datacontract.org/2004/07/WineMonitorService");
                dataDCS.WriteObject(writer, UpdateSensorDataField.data);
                writer.WriteEndElement();
            }
            return;
        }
    }
    
    [DataContract(Namespace="http://localhost/WineMonitorService/")]
    public class UpdateSensorDataResponse
    {
    }
    
    public class UpdateSensorDataResponseDataContractSerializer : DataContractSerializer
    {
        
        public UpdateSensorDataResponseDataContractSerializer(string rootName, string rootNameSpace) : 
                base(rootName, rootNameSpace)
        {
        }
        
        public UpdateSensorDataResponseDataContractSerializer(string rootName, string rootNameSpace, string localNameSpace) : 
                base(rootName, rootNameSpace, localNameSpace)
        {
        }
        
        public override object ReadObject(XmlReader reader)
        {
            UpdateSensorDataResponse UpdateSensorDataResponseField = null;
            if (IsParentStartElement(reader, false, true))
            {
                UpdateSensorDataResponseField = new UpdateSensorDataResponse();
                reader.Read();
                reader.ReadEndElement();
            }
            return UpdateSensorDataResponseField;
        }
        
        public override void WriteObject(XmlWriter writer, object graph)
        {
            UpdateSensorDataResponse UpdateSensorDataResponseField = ((UpdateSensorDataResponse)(graph));
            if (WriteParentElement(writer, true, true, graph))
            {
                writer.WriteEndElement();
            }
            return;
        }
    }
    
    [DataContract(Namespace="http://localhost/WineMonitorService/")]
    public class UpdateThresholds
    {
        
        [DataMember(Order=0, IsNillable=true, IsRequired=false)]
        public string cabinetId;
        
        [DataMember(Order=1, IsNillable=true, IsRequired=false)]
        public schemas.datacontract.org.WineMonitorService.WineSensorThreshold data;
    }
    
    public class UpdateThresholdsDataContractSerializer : DataContractSerializer
    {
        
        public UpdateThresholdsDataContractSerializer(string rootName, string rootNameSpace) : 
                base(rootName, rootNameSpace)
        {
        }
        
        public UpdateThresholdsDataContractSerializer(string rootName, string rootNameSpace, string localNameSpace) : 
                base(rootName, rootNameSpace, localNameSpace)
        {
        }
        
        public override object ReadObject(XmlReader reader)
        {
            UpdateThresholds UpdateThresholdsField = null;
            if (IsParentStartElement(reader, false, true))
            {
                UpdateThresholdsField = new UpdateThresholds();
                reader.Read();
                if (IsChildStartElement(reader, "cabinetId", true, false))
                {
                    reader.Read();
                    UpdateThresholdsField.cabinetId = reader.ReadString();
                    reader.ReadEndElement();
                }
                schemas.datacontract.org.WineMonitorService.WineSensorThresholdDataContractSerializer dataDCS = new schemas.datacontract.org.WineMonitorService.WineSensorThresholdDataContractSerializer("data", "http://localhost/WineMonitorService/", "http://schemas.datacontract.org/2004/07/WineMonitorService");
                UpdateThresholdsField.data = ((schemas.datacontract.org.WineMonitorService.WineSensorThreshold)(dataDCS.ReadObject(reader)));
                reader.ReadEndElement();
            }
            return UpdateThresholdsField;
        }
        
        public override void WriteObject(XmlWriter writer, object graph)
        {
            UpdateThresholds UpdateThresholdsField = ((UpdateThresholds)(graph));
            if (WriteParentElement(writer, true, true, graph))
            {
                if (WriteChildElement(writer, "cabinetId", true, false, UpdateThresholdsField.cabinetId))
                {
                    writer.WriteString(UpdateThresholdsField.cabinetId);
                    writer.WriteEndElement();
                }
                schemas.datacontract.org.WineMonitorService.WineSensorThresholdDataContractSerializer dataDCS = new schemas.datacontract.org.WineMonitorService.WineSensorThresholdDataContractSerializer("data", "http://localhost/WineMonitorService/", "http://schemas.datacontract.org/2004/07/WineMonitorService");
                dataDCS.WriteObject(writer, UpdateThresholdsField.data);
                writer.WriteEndElement();
            }
            return;
        }
    }
    
    [DataContract(Namespace="http://localhost/WineMonitorService/")]
    public class UpdateThresholdsResponse
    {
    }
    
    public class UpdateThresholdsResponseDataContractSerializer : DataContractSerializer
    {
        
        public UpdateThresholdsResponseDataContractSerializer(string rootName, string rootNameSpace) : 
                base(rootName, rootNameSpace)
        {
        }
        
        public UpdateThresholdsResponseDataContractSerializer(string rootName, string rootNameSpace, string localNameSpace) : 
                base(rootName, rootNameSpace, localNameSpace)
        {
        }
        
        public override object ReadObject(XmlReader reader)
        {
            UpdateThresholdsResponse UpdateThresholdsResponseField = null;
            if (IsParentStartElement(reader, false, true))
            {
                UpdateThresholdsResponseField = new UpdateThresholdsResponse();
                reader.Read();
                reader.ReadEndElement();
            }
            return UpdateThresholdsResponseField;
        }
        
        public override void WriteObject(XmlWriter writer, object graph)
        {
            UpdateThresholdsResponse UpdateThresholdsResponseField = ((UpdateThresholdsResponse)(graph));
            if (WriteParentElement(writer, true, true, graph))
            {
                writer.WriteEndElement();
            }
            return;
        }
    }
    
    [DataContract(Namespace="http://localhost/WineMonitorService/")]
    public class Alert
    {
        
        [DataMember(Order=0, IsNillable=true, IsRequired=false)]
        public string cabinetId;
        
        [DataMember(Order=1, IsNillable=true, IsRequired=false)]
        public schemas.datacontract.org.WineMonitorService.AlertData alert;
    }
    
    public class AlertDataContractSerializer : DataContractSerializer
    {
        
        public AlertDataContractSerializer(string rootName, string rootNameSpace) : 
                base(rootName, rootNameSpace)
        {
        }
        
        public AlertDataContractSerializer(string rootName, string rootNameSpace, string localNameSpace) : 
                base(rootName, rootNameSpace, localNameSpace)
        {
        }
        
        public override object ReadObject(XmlReader reader)
        {
            Alert AlertField = null;
            if (IsParentStartElement(reader, false, true))
            {
                AlertField = new Alert();
                reader.Read();
                if (IsChildStartElement(reader, "cabinetId", true, false))
                {
                    reader.Read();
                    AlertField.cabinetId = reader.ReadString();
                    reader.ReadEndElement();
                }
                schemas.datacontract.org.WineMonitorService.AlertDataDataContractSerializer alertDCS = new schemas.datacontract.org.WineMonitorService.AlertDataDataContractSerializer("alert", "http://localhost/WineMonitorService/", "http://schemas.datacontract.org/2004/07/WineMonitorService");
                AlertField.alert = ((schemas.datacontract.org.WineMonitorService.AlertData)(alertDCS.ReadObject(reader)));
                reader.ReadEndElement();
            }
            return AlertField;
        }
        
        public override void WriteObject(XmlWriter writer, object graph)
        {
            Alert AlertField = ((Alert)(graph));
            if (WriteParentElement(writer, true, true, graph))
            {
                if (WriteChildElement(writer, "cabinetId", true, false, AlertField.cabinetId))
                {
                    writer.WriteString(AlertField.cabinetId);
                    writer.WriteEndElement();
                }
                schemas.datacontract.org.WineMonitorService.AlertDataDataContractSerializer alertDCS = new schemas.datacontract.org.WineMonitorService.AlertDataDataContractSerializer("alert", "http://localhost/WineMonitorService/", "http://schemas.datacontract.org/2004/07/WineMonitorService");
                alertDCS.WriteObject(writer, AlertField.alert);
                writer.WriteEndElement();
            }
            return;
        }
    }
    
    [DataContract(Namespace="http://localhost/WineMonitorService/")]
    public class AlertResponse
    {
    }
    
    public class AlertResponseDataContractSerializer : DataContractSerializer
    {
        
        public AlertResponseDataContractSerializer(string rootName, string rootNameSpace) : 
                base(rootName, rootNameSpace)
        {
        }
        
        public AlertResponseDataContractSerializer(string rootName, string rootNameSpace, string localNameSpace) : 
                base(rootName, rootNameSpace, localNameSpace)
        {
        }
        
        public override object ReadObject(XmlReader reader)
        {
            AlertResponse AlertResponseField = null;
            if (IsParentStartElement(reader, false, true))
            {
                AlertResponseField = new AlertResponse();
                reader.Read();
                reader.ReadEndElement();
            }
            return AlertResponseField;
        }
        
        public override void WriteObject(XmlWriter writer, object graph)
        {
            AlertResponse AlertResponseField = ((AlertResponse)(graph));
            if (WriteParentElement(writer, true, true, graph))
            {
                writer.WriteEndElement();
            }
            return;
        }
    }
    
    [ServiceContract(Namespace="http://localhost/WineMonitorService/")]
    public interface IIWineMonitorUpdate
    {
        
        [OperationContract(Action="http://localhost/WineMonitorService/IWineMonitorUpdate/RegisterWineCabinet")]
        RegisterWineCabinetResponse RegisterWineCabinet(RegisterWineCabinet req);
        
        [OperationContract(Action="http://localhost/WineMonitorService/IWineMonitorUpdate/UpdateSensorData")]
        UpdateSensorDataResponse UpdateSensorData(UpdateSensorData req);
        
        [OperationContract(Action="http://localhost/WineMonitorService/IWineMonitorUpdate/UpdateThresholds")]
        UpdateThresholdsResponse UpdateThresholds(UpdateThresholds req);
        
        [OperationContract(Action="http://localhost/WineMonitorService/IWineMonitorUpdate/Alert")]
        AlertResponse Alert(Alert req);
    }
}
namespace schemas.datacontract.org.WineMonitorService
{
    
    
    [DataContract(Namespace="http://schemas.datacontract.org/2004/07/WineMonitorService")]
    public class WineSensorData
    {
        
        [DataMember(Order=0, IsRequired=false)]
        public double Humidity;
        
        [DataMember(Order=1, IsRequired=false)]
        public double Temperature;
        
        [DataMember(Order=2, IsRequired=false)]
        public System.DateTime TimeStamp;
    }
    
    public class WineSensorDataDataContractSerializer : DataContractSerializer
    {
        
        public WineSensorDataDataContractSerializer(string rootName, string rootNameSpace) : 
                base(rootName, rootNameSpace)
        {
        }
        
        public WineSensorDataDataContractSerializer(string rootName, string rootNameSpace, string localNameSpace) : 
                base(rootName, rootNameSpace, localNameSpace)
        {
        }
        
        public override object ReadObject(XmlReader reader)
        {
            WineSensorData WineSensorDataField = null;
            if (IsParentStartElement(reader, false, true))
            {
                WineSensorDataField = new WineSensorData();
                reader.Read();
                if (IsChildStartElement(reader, "Humidity", false, false))
                {
                    reader.Read();
                    WineSensorDataField.Humidity = XmlConvert.ToDouble(reader.ReadString());
                    reader.ReadEndElement();
                }
                if (IsChildStartElement(reader, "Temperature", false, false))
                {
                    reader.Read();
                    WineSensorDataField.Temperature = XmlConvert.ToDouble(reader.ReadString());
                    reader.ReadEndElement();
                }
                if (IsChildStartElement(reader, "TimeStamp", false, false))
                {
                    reader.Read();
                    WineSensorDataField.TimeStamp = XmlConvert.ToDateTime(reader.ReadString());
                    reader.ReadEndElement();
                }
                reader.ReadEndElement();
            }
            return WineSensorDataField;
        }
        
        public override void WriteObject(XmlWriter writer, object graph)
        {
            WineSensorData WineSensorDataField = ((WineSensorData)(graph));
            if (WriteParentElement(writer, true, true, graph))
            {
                if (WriteChildElement(writer, "Humidity", false, false, WineSensorDataField.Humidity))
                {
                    writer.WriteString(XmlConvert.ToString(WineSensorDataField.Humidity));
                    writer.WriteEndElement();
                }
                if (WriteChildElement(writer, "Temperature", false, false, WineSensorDataField.Temperature))
                {
                    writer.WriteString(XmlConvert.ToString(WineSensorDataField.Temperature));
                    writer.WriteEndElement();
                }
                if (WriteChildElement(writer, "TimeStamp", false, false, WineSensorDataField.TimeStamp))
                {
                    writer.WriteString(XmlConvert.ToString(WineSensorDataField.TimeStamp));
                    writer.WriteEndElement();
                }
                writer.WriteEndElement();
            }
            return;
        }
    }
    
    [DataContract(Namespace="http://schemas.datacontract.org/2004/07/WineMonitorService")]
    public class WineSensorThreshold
    {
        
        [DataMember(Order=0, IsRequired=false)]
        public double MaxHumidity;
        
        [DataMember(Order=1, IsRequired=false)]
        public int MaxMinutesWithoutUpdate;
        
        [DataMember(Order=2, IsRequired=false)]
        public double MaxTemperature;
        
        [DataMember(Order=3, IsRequired=false)]
        public double MinHumidity;
        
        [DataMember(Order=4, IsRequired=false)]
        public double MinTemperature;
        
        [DataMember(Order=5, IsRequired=false)]
        public System.DateTime TimeStamp;
    }
    
    public class WineSensorThresholdDataContractSerializer : DataContractSerializer
    {
        
        public WineSensorThresholdDataContractSerializer(string rootName, string rootNameSpace) : 
                base(rootName, rootNameSpace)
        {
        }
        
        public WineSensorThresholdDataContractSerializer(string rootName, string rootNameSpace, string localNameSpace) : 
                base(rootName, rootNameSpace, localNameSpace)
        {
        }
        
        public override object ReadObject(XmlReader reader)
        {
            WineSensorThreshold WineSensorThresholdField = null;
            if (IsParentStartElement(reader, false, true))
            {
                WineSensorThresholdField = new WineSensorThreshold();
                reader.Read();
                if (IsChildStartElement(reader, "MaxHumidity", false, false))
                {
                    reader.Read();
                    WineSensorThresholdField.MaxHumidity = XmlConvert.ToDouble(reader.ReadString());
                    reader.ReadEndElement();
                }
                if (IsChildStartElement(reader, "MaxMinutesWithoutUpdate", false, false))
                {
                    reader.Read();
                    WineSensorThresholdField.MaxMinutesWithoutUpdate = XmlConvert.ToInt32(reader.ReadString());
                    reader.ReadEndElement();
                }
                if (IsChildStartElement(reader, "MaxTemperature", false, false))
                {
                    reader.Read();
                    WineSensorThresholdField.MaxTemperature = XmlConvert.ToDouble(reader.ReadString());
                    reader.ReadEndElement();
                }
                if (IsChildStartElement(reader, "MinHumidity", false, false))
                {
                    reader.Read();
                    WineSensorThresholdField.MinHumidity = XmlConvert.ToDouble(reader.ReadString());
                    reader.ReadEndElement();
                }
                if (IsChildStartElement(reader, "MinTemperature", false, false))
                {
                    reader.Read();
                    WineSensorThresholdField.MinTemperature = XmlConvert.ToDouble(reader.ReadString());
                    reader.ReadEndElement();
                }
                if (IsChildStartElement(reader, "TimeStamp", false, false))
                {
                    reader.Read();
                    WineSensorThresholdField.TimeStamp = XmlConvert.ToDateTime(reader.ReadString());
                    reader.ReadEndElement();
                }
                reader.ReadEndElement();
            }
            return WineSensorThresholdField;
        }
        
        public override void WriteObject(XmlWriter writer, object graph)
        {
            WineSensorThreshold WineSensorThresholdField = ((WineSensorThreshold)(graph));
            if (WriteParentElement(writer, true, true, graph))
            {
                if (WriteChildElement(writer, "MaxHumidity", false, false, WineSensorThresholdField.MaxHumidity))
                {
                    writer.WriteString(XmlConvert.ToString(WineSensorThresholdField.MaxHumidity));
                    writer.WriteEndElement();
                }
                if (WriteChildElement(writer, "MaxMinutesWithoutUpdate", false, false, WineSensorThresholdField.MaxMinutesWithoutUpdate))
                {
                    writer.WriteString(XmlConvert.ToString(WineSensorThresholdField.MaxMinutesWithoutUpdate));
                    writer.WriteEndElement();
                }
                if (WriteChildElement(writer, "MaxTemperature", false, false, WineSensorThresholdField.MaxTemperature))
                {
                    writer.WriteString(XmlConvert.ToString(WineSensorThresholdField.MaxTemperature));
                    writer.WriteEndElement();
                }
                if (WriteChildElement(writer, "MinHumidity", false, false, WineSensorThresholdField.MinHumidity))
                {
                    writer.WriteString(XmlConvert.ToString(WineSensorThresholdField.MinHumidity));
                    writer.WriteEndElement();
                }
                if (WriteChildElement(writer, "MinTemperature", false, false, WineSensorThresholdField.MinTemperature))
                {
                    writer.WriteString(XmlConvert.ToString(WineSensorThresholdField.MinTemperature));
                    writer.WriteEndElement();
                }
                if (WriteChildElement(writer, "TimeStamp", false, false, WineSensorThresholdField.TimeStamp))
                {
                    writer.WriteString(XmlConvert.ToString(WineSensorThresholdField.TimeStamp));
                    writer.WriteEndElement();
                }
                writer.WriteEndElement();
            }
            return;
        }
    }
    
    [DataContract(Namespace="http://schemas.datacontract.org/2004/07/WineMonitorService")]
    public enum AlertFlags
    {
        
        [EnumMember()]
        None,
        
        [EnumMember()]
        TempHigh,
        
        [EnumMember()]
        TempLow,
        
        [EnumMember()]
        HumidHigh,
        
        [EnumMember()]
        HumidLow,
        
        [EnumMember()]
        NoComm,
    }
    
    public class AlertFlagsDataContractSerializer : DataContractSerializer
    {
        
        public AlertFlagsDataContractSerializer(string rootName, string rootNameSpace) : 
                base(rootName, rootNameSpace)
        {
        }
        
        public AlertFlagsDataContractSerializer(string rootName, string rootNameSpace, string localNameSpace) : 
                base(rootName, rootNameSpace, localNameSpace)
        {
        }
        
        public override object ReadObject(XmlReader reader)
        {
            AlertFlags AlertFlagsField = 0;
            if (IsParentStartElement(reader, false, true))
            {
                AlertFlagsField = new AlertFlags();
				switch(reader.ReadString())
				{
					case "None":
                		AlertFlagsField = AlertFlags.None;
                		break;
					case "TempHigh":
                		AlertFlagsField = AlertFlags.TempHigh;
                		break;
					case "TempLow":
                		AlertFlagsField = AlertFlags.TempLow;
                		break;
					case "HumidHigh":
                		AlertFlagsField = AlertFlags.HumidHigh;
                		break;
					case "HumidLow":
                		AlertFlagsField = AlertFlags.HumidLow;
                		break;
					case "NoComm":
                		AlertFlagsField = AlertFlags.NoComm;
                		break;
					default:
                		throw new XmlException();
				}
                reader.ReadEndElement();
            }
            return AlertFlagsField;
        }
        
        public override void WriteObject(XmlWriter writer, object graph)
        {
            AlertFlags AlertFlagsField = ((AlertFlags)(graph));
            if (WriteParentElement(writer, true, true, graph))
            {
				switch(AlertFlagsField)
				{
					case AlertFlags.None:
                		writer.WriteString("None");
                		break;
					case AlertFlags.TempHigh:
                		writer.WriteString("TempHigh");
                		break;
					case AlertFlags.TempLow:
                		writer.WriteString("TempLow");
                		break;
					case AlertFlags.HumidHigh:
                		writer.WriteString("HumidHigh");
                		break;
					case AlertFlags.HumidLow:
                		writer.WriteString("HumidLow");
                		break;
					case AlertFlags.NoComm:
                		writer.WriteString("NoComm");
                		break;
					default:
                		throw new XmlException();
				}
                writer.WriteEndElement();
            }
            return;
        }
    }
    
    [DataContract(Namespace="http://schemas.datacontract.org/2004/07/WineMonitorService")]
    public class AlertData
    {
        
        [DataMember(Order=0, IsRequired=false)]
        public AlertFlags Alert;
        
        [DataMember(Order=1, IsRequired=false)]
        public double AlertValue;
        
        [DataMember(Order=2, IsRequired=false)]
        public System.DateTime TimeStamp;
    }
    
    public class AlertDataDataContractSerializer : DataContractSerializer
    {
        
        public AlertDataDataContractSerializer(string rootName, string rootNameSpace) : 
                base(rootName, rootNameSpace)
        {
        }
        
        public AlertDataDataContractSerializer(string rootName, string rootNameSpace, string localNameSpace) : 
                base(rootName, rootNameSpace, localNameSpace)
        {
        }
        
        public override object ReadObject(XmlReader reader)
        {
            AlertData AlertDataField = null;
            if (IsParentStartElement(reader, false, true))
            {
                AlertDataField = new AlertData();
                reader.Read();
                AlertFlagsDataContractSerializer AlertDCS = new AlertFlagsDataContractSerializer("Alert", "http://schemas.datacontract.org/2004/07/WineMonitorService", "http://schemas.datacontract.org/2004/07/WineMonitorService");
                AlertDataField.Alert = ((AlertFlags)(AlertDCS.ReadObject(reader)));
                if (IsChildStartElement(reader, "AlertValue", false, false))
                {
                    reader.Read();
                    AlertDataField.AlertValue = XmlConvert.ToDouble(reader.ReadString());
                    reader.ReadEndElement();
                }
                if (IsChildStartElement(reader, "TimeStamp", false, false))
                {
                    reader.Read();
                    AlertDataField.TimeStamp = XmlConvert.ToDateTime(reader.ReadString());
                    reader.ReadEndElement();
                }
                reader.ReadEndElement();
            }
            return AlertDataField;
        }
        
        public override void WriteObject(XmlWriter writer, object graph)
        {
            AlertData AlertDataField = ((AlertData)(graph));
            if (WriteParentElement(writer, true, true, graph))
            {
                AlertFlagsDataContractSerializer AlertDCS = new AlertFlagsDataContractSerializer("Alert", "http://schemas.datacontract.org/2004/07/WineMonitorService", "http://schemas.datacontract.org/2004/07/WineMonitorService");
                AlertDCS.WriteObject(writer, AlertDataField.Alert);
                if (WriteChildElement(writer, "AlertValue", false, false, AlertDataField.AlertValue))
                {
                    writer.WriteString(XmlConvert.ToString(AlertDataField.AlertValue));
                    writer.WriteEndElement();
                }
                if (WriteChildElement(writer, "TimeStamp", false, false, AlertDataField.TimeStamp))
                {
                    writer.WriteString(XmlConvert.ToString(AlertDataField.TimeStamp));
                    writer.WriteEndElement();
                }
                writer.WriteEndElement();
            }
            return;
        }
    }
}
