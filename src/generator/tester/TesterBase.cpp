#include "TesterBase.hpp"
#include "TesterController.hpp"
#include "TesterDomain.hpp"

namespace Tester
{
  TesterBase * TesterBase::get_tester( Collector::FileGrails * ptr_data )
  {
    std::string category = ptr_data->layer;

    TesterBase * instance;

    if( !category.compare( "Controller" ) )
    {
      instance = new TesterController( ptr_data );
    } else if( !category.compare( "Domain" ) )
    {
      instance = new TesterDomain( ptr_data );
    }

    return instance;
  }

  void TesterBase::conclude_data( std::fstream * test_stream )
  {
    (* test_stream ) << "}" << std::endl;
  }

  void TesterBase::set_data( Collector::FileGrails * ptr )
  {
      this->data_ptr = ptr;
  }

  std::string TesterBase::convert_to_lower( std::string text )
  {
    std::string lower_text;

    for( int i = 0; i < text.size(); i++ )
    {
      lower_text += std::tolower( text[ i ], locale );
    }

    return lower_text;
  }
}
