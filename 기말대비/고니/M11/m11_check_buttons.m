function varargout = m11_check_buttons(varargin)
% M11_CHECK_BUTTONS MATLAB code for m11_check_buttons.fig
%      M11_CHECK_BUTTONS, by itself, creates a new M11_CHECK_BUTTONS or raises the existing
%      singleton*.
%
%      H = M11_CHECK_BUTTONS returns the handle to a new M11_CHECK_BUTTONS or the handle to
%      the existing singleton*.
%
%      M11_CHECK_BUTTONS('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in M11_CHECK_BUTTONS.M with the given input arguments.
%
%      M11_CHECK_BUTTONS('Property','Value',...) creates a new M11_CHECK_BUTTONS or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before m11_check_buttons_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to m11_check_buttons_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help m11_check_buttons

% Last Modified by GUIDE v2.5 16-May-2015 10:14:48

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @m11_check_buttons_OpeningFcn, ...
                   'gui_OutputFcn',  @m11_check_buttons_OutputFcn, ...
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


% --- Executes just before m11_check_buttons is made visible.
function m11_check_buttons_OpeningFcn(hObject, eventdata, handles, varargin)
handles.output = hObject;
handles.price  = 5;
guidata(hObject, handles);

% UIWAIT makes m11_check_buttons wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = m11_check_buttons_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in checkbox1.
function checkbox1_Callback(hObject, eventdata, handles)
update_price(hObject, handles, 2);

function checkbox2_Callback(hObject, eventdata, handles)
update_price(hObject, handles, 1);

function checkbox3_Callback(hObject, eventdata, handles)
update_price(hObject, handles, 1.5);

function update_price(hObject, handles, price )

if get(hObject,'Value') == 1
    handles.price = handles.price + price;
else
    handles.price = handles.price - price;
end
set( handles.text3, 'String', ...
    sprintf('the total price : $%.2f', handles.price));
guidata(hObject, handles);
