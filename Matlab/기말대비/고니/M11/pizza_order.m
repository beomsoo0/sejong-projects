function varargout = pizza_order(varargin)
% PIZZA_ORDER MATLAB code for pizza_order.fig
%      PIZZA_ORDER, by itself, creates a new PIZZA_ORDER or raises the existing
%      singleton*.
%
%      H = PIZZA_ORDER returns the handle to a new PIZZA_ORDER or the handle to
%      the existing singleton*.
%
%      PIZZA_ORDER('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in PIZZA_ORDER.M with the given input arguments.
%
%      PIZZA_ORDER('Property','Value',...) creates a new PIZZA_ORDER or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before pizza_order_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to pizza_order_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help pizza_order

% Last Modified by GUIDE v2.5 09-May-2016 22:47:58

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @pizza_order_OpeningFcn, ...
                   'gui_OutputFcn',  @pizza_order_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before pizza_order is made visible.
function pizza_order_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to pizza_order (see VARARGIN)

% Choose default command line output for pizza_order
handles.output = hObject;

% Update handles structure
handles.topping = zeros(4);
handles.topping_text = {'Ä¡Áî', 'ÆäÆÛ', '¾ØÃÊºñ', '¹ö¼¸'};
guidata(hObject, handles);

% UIWAIT makes pizza_order wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = pizza_order_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes when selected object is changed in uibuttongroup1.
function uibuttongroup1_SelectionChangedFcn(hObject, eventdata, handles)
% hObject    handle to the selected object in uibuttongroup1 
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set( handles.text_pizza_size, 'String', hObject.String );


% --- Executes on button press in pb_order.
function pb_order_Callback(hObject, eventdata, handles)
% hObject    handle to pb_order (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
fprintf( '%d %s pizza has been ordered!\n', ...
    get(handles.slider_pizza_count, 'Value'), ...
    get(handles.text_pizza_size,'String') );
fprintf( 'topping: %s\n', get( handles.text_topping, 'String' ) );
close(gcf);
delete(hObject);


% --- Executes on slider movement.
function slider_pizza_count_Callback(hObject, eventdata, handles)
% hObject    handle to slider_pizza_count (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
v = get(hObject,'Value');
n = round(v);
set( hObject, 'Value', n );
set( handles.text_pizza_count, 'String', num2str(n) );

% --- Executes during object creation, after setting all properties.
function slider_pizza_count_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider_pizza_count (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes on button press in chk_cheese.
function chk_cheese_Callback(hObject, eventdata, handles)
% hObject    handle to chk_cheese (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.topping(1) = get(hObject,'Value');
topping = '';
first_topping = 1;
for n=1:4
    if handles.topping(n)==1
        if first_topping == 1
            topping = strcat( topping, handles.topping_text{n} );
        else
            topping = strcat( strcat(topping,', '), handles.topping_text{n} );
        end
        first_topping = 0;
    end
end
set( handles.text_topping, 'String', topping );
guidata(hObject, handles);


% --- Executes on button press in chk_pepper.
function chk_pepper_Callback(hObject, eventdata, handles)
% hObject    handle to chk_pepper (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.topping(2) = get(hObject,'Value');
topping = '';
first_topping = 1;
for n=1:4
    if handles.topping(n)==1
        if first_topping == 1
            topping = strcat( topping, handles.topping_text{n} );
        else
            topping = strcat( strcat(topping,', '), handles.topping_text{n} );
        end
        first_topping = 0;
    end
end
set( handles.text_topping, 'String', topping );
guidata(hObject, handles);


% --- Executes on button press in chk_anchovy.
function chk_anchovy_Callback(hObject, eventdata, handles)
% hObject    handle to chk_anchovy (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.topping(3) = get(hObject,'Value');
topping = '';
first_topping = 1;
for n=1:4
    if handles.topping(n)==1
        if first_topping == 1
            topping = strcat( topping, handles.topping_text{n} );
        else
            topping = strcat( strcat(topping,', '), handles.topping_text{n} );
        end
        first_topping = 0;
    end
end
set( handles.text_topping, 'String', topping );
guidata(hObject, handles);


% --- Executes on button press in chk_mushroom.
function chk_mushroom_Callback(hObject, eventdata, handles)
% hObject    handle to chk_mushroom (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.topping(4) = get(hObject,'Value');
topping = '';
first_topping = 1;
for n=1:4
    if handles.topping(n)==1
        if first_topping == 1
            topping = strcat( topping, handles.topping_text{n} );
        else
            topping = strcat( strcat(topping,', '), handles.topping_text{n} );
        end
        first_topping = 0;
    end
end
set( handles.text_topping, 'String', topping );
guidata(hObject, handles);
