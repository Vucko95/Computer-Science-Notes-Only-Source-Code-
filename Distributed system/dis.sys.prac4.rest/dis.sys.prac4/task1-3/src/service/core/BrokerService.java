package service.core;
import java.util.List;
import service.registry.Service;

public interface BrokerService extends Service { public List<Quotation> getQuotations(ClientInfo info); }
