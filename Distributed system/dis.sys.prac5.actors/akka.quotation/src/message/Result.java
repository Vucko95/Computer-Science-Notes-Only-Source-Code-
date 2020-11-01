package message;
import java.util.List;
import service.core.Quotation;

public class Result {
  public List<Quotation> quotations;

  public Result(List<Quotation> quotations) { this.quotations = quotations; }
}
