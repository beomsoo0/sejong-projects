function varargout = random_shape(varargin)
% RANDOM_SHAPE MATLAB code for random_shape.fig
%      RANDOM_SHAPE, by itself, creates a new RANDOM_SHAPE or raises the existing
%      singleton*.
%
%      H = RANDOM_SHAPE returns the handle to a new RANDOM_SHAPE or the handle to
%      the existing singleton*.
%
%      RANDOM_SHAPE('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in RANDOM_SHAPE.M with the given input arguments.
%
%      RANDOM_SHAPE('Property','Value',...) creates a new RANDOM_SHAPE or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before random_shape_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to random_shape_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help random_shape

% Last Modified by GUIDE v2.5 18-May-2015 19:11:19

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @random_shape_OpeningFcn, ...
                   'gui_OutputFcn',  @random_shape_OutputFcn, ...
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


% --- Executes just before random_shape is made visible.
function random_shape_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to random_shape (see VARARGIN)

% Choose default command line output for random_shape
handles.output = hObject;

% Draw a rectangle border
handles.color = 'k';
handles.shape = 'Circle';
t = linspace(0, 2*pi, 100);
handles.cx = cos(t);
handles.cy = sin(t);
handles.tx = [0 1 0.5 0];
handles.ty = [0 0 -1 0];
handles.rx = [0 1 1 0 0];   
handles.ry = [0 0 1 1 0];
draw_canvas( handles );

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes random_shape wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = random_shape_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in add_button.
function add_button_Callback(hObject, eventdata, handles)
% hObject    handle to add_button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
disp('Add the selected shape in a random position.');
add_shape( handles );

% --- Executes on button press in reset_button.
function reset_button_Callback(hObject, eventdata, handles)
% hObject    handle to reset_button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
disp('Clear the canvas');
draw_canvas( handles );

% --- Executes on selection change in color_popup.
function color_popup_Callback(hObject, eventdata, handles)
% hObject    handle to color_popup (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns color_popup contents as cell array
%        contents{get(hObject,'Value')} returns selected item from color_popup
c = get(hObject,'Value');
colors = 'kbcgryw';
handles.color = colors(c);
guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function color_popup_CreateFcn(hObject, eventdata, handles)
% hObject    handle to color_popup (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes when selected object is changed in shape_group.
function shape_group_SelectionChangedFcn(hObject, eventdata, handles)
% hObject    handle to the selected object in shape_group 
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.shape = get( hObject, 'String' );
guidata(hObject, handles);

function draw_canvas( handles )
plot([0 1 1 0 0], [0 0 1 1 0], 'b-');
axis([0 1 0 1]); axis off;

function add_shape( handles )
% Draw a selected shape at a random position with random size
% and with the selected color.

% random position
cx = rand(); cy = rand();
sz = 0.1 + 0.3*rand();
switch handles.shape
    case 'Circle'
        x = handles.cx;
        y = handles.cy;
    case 'Triangle'
        x = handles.tx;
        y = handles.ty;
    case 'Square'
        x = handles.rx;
        y = handles.ry;
end
patch( cx + sz*x, cy + sz*y, handles.color );
axis([0 1 0 1]);
