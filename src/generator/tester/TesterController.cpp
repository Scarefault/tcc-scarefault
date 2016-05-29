#include "TesterController.hpp"

namespace Tester
{
  TesterController::TesterController( Helper::Data * ptr_data )
  {
    this->set_data( ptr_data );
  }

  void TesterController::write_data()
  {
    std::fstream test_stream;

    test_stream.open( TESTFILE, WRITE|APPEND );

    if( test_stream.is_open() )
    {
      make_header( &test_stream );
      make_valid_setup( &test_stream );
      make_test_index( &test_stream );
      test_methods( &test_stream );
      TesterBase::conclude_data( &test_stream );

      test_stream.close();
    } else
    {
      std::cout << "Unable to open TESTFILE..." << std::endl;
    }
  }

  void TesterController::make_header( std::fstream * test_stream )
  {
    (* test_stream) << "package " << data_ptr->package_name
                    << std::endl
                    << std::endl
                    << "import org.junit.*"
                    << std::endl
                    << "import grails.test.mixin.*"
                    << std::endl
                    << std::endl
                    << "@TestFor(" << data_ptr->class_name << ")"
                    << std::endl
                    << "class " << data_ptr->class_name << "Tests {"
                    << std::endl
                    << std::endl;
  }

  void TesterController::make_valid_setup( std::fstream * test_stream )
  {
    (* test_stream) << "\tdef populateValidParams(params) {"
                    << std::endl
                    << "\t\tassert params != null"
                    << std::endl
                    << std::endl;

                    create_params( test_stream );

    (* test_stream) << std::endl
                    << "\t}"
                    <<std::endl
                    << std::endl;
  }

  void TesterController::create_params( std::fstream * test_stream )
  {
    for( int i = 0; i < data_ptr->proprieties.size(); i++ )
    {
      Helper::Propriety propriety = data_ptr->proprieties[ i ];

      if( propriety.name.compare( "dateCreated") &&
          propriety.name.compare( "lastUpdated") )
      {
        std::string value = create_value( propriety );

        (* test_stream) << "\t\tparams[\""
                        << propriety.name
                        << "\"] = "
                        << value
                        << std::endl;
      } else
      {
        // Nothing to do
      }
    }
  }

  std::string TesterController::create_value( Helper::Propriety propriety )
  {
    std::string value( "VALID VALUE" );
    std::vector<Helper::Constraint> constraints = propriety.contraints;

    if( is_string( propriety ) )
    {
      value = create_string( propriety );
    } else if( is_integer( propriety ) )
    {
      value = generate_random_integer();
    } else if( is_floating( propriety ) )
    {
      value = generate_random_floating();
    } else if( is_boolean( propriety ) )
    {
      value = generate_random_boolean();
    } else
    {
      // Nothing to do
    }

    return value;
  }

  std::string TesterController::create_string( Helper::Propriety propriety )
  {
    std::string result;
    bool blank = false;
    bool credit_card = false;
    bool email = false;
    bool nullable = false;
    bool url = false;
    int size = 0;

    for( int i = 0; i < propriety.contraints.size(); i++ )
    {
      Helper::Constraint constraint = propriety.contraints[ i ];

      for( int type = 0; type < type_constraint.size(); type++ )
      {
        if( !constraint.name.compare( type_constraint[ type ] ) )
        {
          switch( type )
          {
            case BLANK:
              blank = ( constraint.value == "true" ) ? true : false;
              break;
            case CREDIT_CARD:
              credit_card = ( constraint.value == "true" ) ? true : false;
              break;
            case EMAIL:
              email = ( constraint.value == "true" ) ? true : false;
              break;
            case IN_LIST:
              break;
            case MATCHES:
              break;
            case NOT_EQUAL:
              break;
            case NULLABLE:
              nullable = ( constraint.value == "true" ) ? true : false;
              break;
            case SIZE:
              size = std::stoi( constraint.value );
            case UNIQUE:
              break;
            case URL:
              url = ( constraint.value == "true" ) ? true : false;
              break;
          }
        }
      }
    }

    result =
      generate_random_string( size, url, email, credit_card, blank, nullable );

    return result;
  }

  std::string
    TesterController::generate_random_string( int size, bool url, bool email,
      bool credit_card, bool blank, bool nullable )
  {
    std::string random_string;

    if( !nullable )
    {
      if( !blank )
      {
        if( !url )
        {
          if( !email )
          {
            if( !credit_card )
            {
              static const std::string alphanum =
                  "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

              for( int i = 0; i < size; i++ )
              {
                random_string += alphanum[ rand() % ( alphanum.size()-1 ) ];
              }

              random_string.insert( random_string.begin(), '\"' );
              random_string.insert( random_string.end(), '\"' );
            } else
            {
              random_string = "\"4556647559902\"";
            }
          } else
          {
            random_string = "\"example@gmail.com\"";
          }
        } else
        {
          random_string = "\"www.somthing.com\"";
        }
      } else
      {
        random_string = "";
      }
    } else
    {
      random_string = "null";
    }

    return random_string;
  }

  std::string TesterController::generate_random_integer( int max )
  {
    int random_integer = rand() % max;
    return std::to_string( random_integer );
  }

  std::string TesterController::generate_random_floating( int max, int scale )
  {
    double random_integer = rand() % max;
    double fractional = pow( 0.5, scale );

    double random_double = random_integer + fractional;
    return std::to_string( random_double );
  }

  std::string TesterController::generate_random_boolean()
  {
    int result = rand() % 2;
    std::string random_boolean;

    if( result )
    {
      random_boolean = "true";
    } else
    {
      random_boolean = "false";
    }

    return random_boolean;
  }

  void TesterController::make_test_index( std::fstream * test_stream )
  {
    std::string low_domain = convert_to_lower( data_ptr->domain_base );

    (* test_stream) << "\tvoid testIndex()"
                    << std::endl
                    << "\t\tcontroller.index()"
                    << std::endl
                    << "\t\tassert \"/" << low_domain
                    << "/list\" == response.redirectedUrl"
                    << std::endl
                    << "\t}"
                    << std::endl
                    << std::endl;
  }

  void TesterController::test_methods( std::fstream * test_stream )
  {
    if( (* test_stream).is_open() )
    {
      const int qtd_methods = data_ptr->methods.size();

      for( int i = 0; i < qtd_methods; i++ )
      {
        if( data_ptr->methods[ i ].name == "create" )
        {
          make_test_create( test_stream );
        } else if( data_ptr->methods[ i ].name == "show" )
        {
          make_test_show( test_stream );
        } else if( data_ptr->methods[ i ].name == "delete" )
        {
          make_test_delete( test_stream );
        } else if( data_ptr->methods[ i ].name == "list" )
        {
          make_test_list( test_stream );
        } else if( data_ptr->methods[ i ].name == "save" )
        {
          make_test_save( test_stream );
        } else if( data_ptr->methods[ i ].name == "edit" )
        {
          make_test_edit( test_stream );
        } else if( data_ptr->methods[ i ].name == "update" )
        {
          make_test_update( test_stream );
        }
      }
    } else
    {
      std::cout << "Unable to open TESTFILE..." << std::endl;
    }
  }

  void TesterController::make_test_create( std::fstream * test_stream )
  {
    std::string low_domain = convert_to_lower( data_ptr->domain_base );

    (* test_stream) << "\tvoid testCreate() {" << std::endl
      << "\t\tdef model = controller.create()" << std::endl
      << std::endl
      << "\t\tassert model."<< low_domain << "Instance != null"
      << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  void TesterController::make_test_show( std::fstream * test_stream )
  {
    std::string low_domain = convert_to_lower( data_ptr->domain_base );
    std::string up_domain = data_ptr->domain_base;

    (* test_stream ) << "\tvoid testShow() {" << std::endl
      << "\t\tcontroller show" << std::endl
      << "\t\tassert flash.message != null" << std::endl
      << "\t\tassert response.redirectedUrl == '/" << low_domain << "/list'"
      << std::endl
      << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tdef " << low_domain << " = new " << data_ptr->domain_base
      << "(params)" << std::endl
      << std::endl
      << "\t\tassert " << low_domain << ".save() != null" << std::endl
      << std::endl
      << "\t\tparams.id = " << low_domain << ".id" << std::endl
      << std::endl
      << "\t\tdef model = controller.show()" << std::endl
      << std::endl
      << "\t\tassert model." << low_domain << "Instance == "
      << low_domain << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  void TesterController::make_test_delete( std::fstream * test_stream )
  {
    std::string low_domain = convert_to_lower( data_ptr->domain_base );
    std::string up_domain = data_ptr->domain_base;

    (* test_stream ) << "\tvoid testDelete() {" << std::endl
      << "\t\tcontroller.delete()" << std::endl
      << "\t\tassert flash.message != null" << std::endl
      << "\t\tassert response.redirectedUrl == '/"
      << low_domain << "/list'" << std::endl
      << std::endl
      << "\t\tresponse.reset()" << std::endl
      << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tdef " << low_domain << " = new " << up_domain << "(params)"
      << std::endl
      << std::endl
      << "\t\tassert " << low_domain << ".save() != null" << std::endl
      << "\t\tassert " << up_domain << ".count() == 1" << std::endl
      << std::endl
      << "\t\tparams.id = " << low_domain << ".id" << std::endl
      << std::endl
      << "\t\tcontroller.delete()" << std::endl
      << std::endl
      << "\t\tassert " << low_domain << ".count() == 0" << std::endl
      << "\t\tassert " << low_domain << ".get(" << low_domain << ".id) == null"
      << std::endl
      << "\t\tassert response.redirectedUrl == '/"
      << low_domain << "/list'" << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  void TesterController::make_test_list( std::fstream * test_stream )
  {
    std::string low_domain = convert_to_lower( data_ptr->domain_base );
    std::string up_domain = data_ptr->domain_base;

    (* test_stream ) << "\tvoid testList() {" << std::endl
      << "\t\tdef model = controller.list()" << std::endl
      << std::endl
      << "\t\tassert model." << low_domain << "InstanceList.size() == 0"
      << std::endl
      << "\t\tassert model." << low_domain << "InstanceTotal == 0" << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  void TesterController::make_test_save( std::fstream * test_stream )
  {
    std::string low_domain = convert_to_lower( data_ptr->domain_base );
    std::string up_domain = data_ptr->domain_base;

    (* test_stream ) << "\tvoid testSave() {" << std::endl
      << "\t\tcontroller.save()" << std::endl
      << std::endl
      << "\t\tassert model." << low_domain
      << "Instance != null" << std::endl
      << "\t\tassert view == '/" << low_domain << "/create'" << std::endl
      << std::endl
      << "\t\tresponse.reset()" << std::endl
      << "" << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tcontroller.save()" << std::endl
      << std::endl
      << "\t\tassert response.redirectedUrl == '/"
      << low_domain << "/show/1'" << std::endl
      << "\t\tassert controller.flash.message != null" << std::endl
      << "\t\tassert " << up_domain << ".count() == 1" << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  void TesterController::make_test_edit( std::fstream * test_stream )
  {
    std::string low_domain = convert_to_lower( data_ptr->domain_base );
    std::string up_domain = data_ptr->domain_base;

    (* test_stream ) << "\tvoid testEdit() {" << std::endl
      << "\t\tcontroller.edit()" << std::endl
      << std::endl
      << "\t\tassert flash.message != null" << std::endl
      << "\t\tassert response.redirectedUrl == '/"
      << low_domain << "/list'" << std::endl
      << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tdef " << low_domain << " = new " << up_domain << "(params)"
      << std::endl
      << std::endl
      << "\t\tassert " << low_domain << ".save() != null" << std::endl
      << std::endl
      << "\t\tparams.id = " << low_domain << ".id" << std::endl
      << std::endl
      << "\t\tdef model = controller.edit()" << std::endl
      << std::endl
      << "\t\tassert model." << low_domain << "Instance == "
      << low_domain << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  void TesterController::make_test_update( std::fstream * test_stream )
  {
    std::string low_domain = convert_to_lower( data_ptr->domain_base );
    std::string up_domain = data_ptr->domain_base;

    (* test_stream ) << "\tvoid testUpdate() {" << std::endl
      << "\t\tcontroller.update()" << std::endl
      << std::endl
      << "\t\tassert flash.message != null" << std::endl
      << "\t\tassert response.redirectedUrl == '/" << low_domain << "/list'"
      << std::endl
      << std::endl
      << "\t\tresponse.reset()" << std::endl
      << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tdef " << low_domain << " = new " << up_domain << "(params)"
      << std::endl
      << std::endl
      << "\t\tassert " << low_domain << ".save() != null" << std::endl
      << std::endl
      << "\t\t// test invalid parameters in update" << std::endl
      << "\t\tparams.id = " << low_domain << ".id" << std::endl
      << "\t\t//TODO: add invalid values to params object" << std::endl
      << std::endl
      << "\t\tcontroller.update()" << std::endl
      << std::endl
      << "\t\tassert view == \"/" << low_domain << "/edit\"" << std::endl
      << "\t\tassert model." << low_domain << "Instance != null" << std::endl
      << std::endl
      << "\t\tuser.clearErrors()" << std::endl
      << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tcontroller.update()" << std::endl
      << std::endl
      << "\t\tassert response.redirectedUrl == \"/" << low_domain
      << "/show/$" << low_domain << ".id\"" << std::endl
      << "\t\tassert flash.message != null" << std::endl
      << std::endl
      << "\t\tresponse.reset()" << std::endl
      << "\t\t" << low_domain << ".clearErrors()" << std::endl
      << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tparams.id = " << low_domain << ".id" << std::endl
      << "\t\tparams.version = -1" << std::endl
      << "\t\tcontroller.update()" << std::endl
      << std::endl
      << "\t\tassert view == \"/" << low_domain << "/edit\"" << std::endl
      << "\t\tassert model." << low_domain << "Instance != null" << std::endl
      << "\t\tassert model." << low_domain
      << "Instance.errors.getFieldError('version')" << std::endl
      << "\t\tassert flash.message != null" << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  bool TesterController::is_string( Helper::Propriety propriety )
  {
    bool is_string = false;

    if( !propriety.type.compare( "String" ) )
    {
      is_string = true;
    } else
    {
      // Nothing to do
    }

    return is_string;
  }

  bool TesterController::is_integer( Helper::Propriety propriety )
  {
    bool is_integer = false;

    if( !propriety.type.compare( "Integer" ) || !propriety.type.compare( "int" ) )
    {
      is_integer = true;
    } else
    {
      // Nothing to do
    }

    return is_integer;
  }

  bool TesterController::is_floating( Helper::Propriety propriety )
  {
    bool is_floating = false;

    if( !propriety.type.compare( "Double" ) || !propriety.type.compare( "double" ) ||
        !propriety.type.compare( "Float" ) || !propriety.type.compare( "float" ) )
    {
      is_floating = true;
    } else
    {
      // Nothing to do
    }

    return is_floating;
  }

  bool TesterController::is_boolean( Helper::Propriety propriety )
  {
    bool is_boolean = false;

    if( !propriety.type.compare( "boolean" ) )
    {
      is_boolean = true;
    } else
    {
      // Nothing to do
    }

    return is_boolean;
  }
}
