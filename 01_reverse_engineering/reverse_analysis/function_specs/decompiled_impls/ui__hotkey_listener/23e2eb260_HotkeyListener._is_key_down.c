/* ===== 23e2eb260 ui.hotkey_listener:111 ===== */
/* ghidra_name=FUN_23e2eb260 entry=23e2eb260 size=1516 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2eb260(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  code *pcVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong lVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar7 = _DAT_23eeb0108;
  plVar2 = (longlong *)*param_3;
  plVar3 = (longlong *)param_3[1];
  if (_DAT_23eeb0108 == (longlong *)0x0) {
LAB_23e2eb29e:
    _DAT_23eeb0108 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb0100,DAT_23eeb0170,0x10);
  }
  else {
    lVar10 = *_DAT_23eeb0108;
    if (1 < lVar10) {
      *_DAT_23eeb0108 = lVar10 + -1;
      goto LAB_23e2eb29e;
    }
    if (_DAT_23eeb0108[2] != 0) {
      *_DAT_23eeb0108 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e2eb29e;
    }
  }
  plVar4 = _DAT_23eeb0108;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23eeb0108 + 9;
  lVar12 = *(longlong *)(lVar10 + 8);
  _DAT_23eeb0108[0xf] = lVar12;
  *(longlong **)(lVar10 + 8) = plVar7;
  if ((lVar12 != 0) &&
     (((*(char *)(lVar12 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar12 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar12 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar12 + 0x38))) && (plVar4[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar12 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  lVar12 = DAT_23eead080;
  *plVar4 = *plVar4 + 1;
  *(undefined4 *)(plVar4 + 8) = 0;
  lVar10 = *(longlong *)(lVar12 + 0x20);
  if (*(char *)(lVar10 + 10) == '\0') {
    plVar7 = (longlong *)FUN_23a37a020(lVar12,_DAT_23eead1b8);
    if (plVar7 == (longlong *)0x0) goto LAB_23e2eb4d9;
    lVar12 = *plVar7;
LAB_23e2eb768:
    if (lVar12 == 0) goto LAB_23e2eb4d9;
  }
  else {
    iVar6 = *(int *)(lVar10 + 0xc);
    if (*(int *)(lVar10 + 0xc) == 0) {
      *(int *)(lVar10 + 0xc) = DAT_23ec14e3c;
      iVar6 = DAT_23ec14e3c;
      DAT_23ec14e3c = DAT_23ec14e3c + 1;
    }
    if (_DAT_23ec14e38 != iVar6) {
      _DAT_23ec14e38 = iVar6;
      _DAT_23eeb00f8 = FUN_23e8cbd60(lVar10,_DAT_23eead1b8,*(undefined8 *)(_DAT_23eead1b8 + 0x18));
    }
    if (-1 < _DAT_23eeb00f8) {
      lVar1 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
      lVar12 = *(longlong *)(lVar1 + 8 + _DAT_23eeb00f8 * 0x10);
      if (lVar12 != 0) goto LAB_23e2eb38e;
      _DAT_23eeb00f8 = FUN_23e8cbd60(lVar10,_DAT_23eead1b8,*(undefined8 *)(_DAT_23eead1b8 + 0x18));
      if (-1 < _DAT_23eeb00f8) {
        lVar12 = *(longlong *)(lVar1 + 8 + _DAT_23eeb00f8 * 0x10);
        goto LAB_23e2eb768;
      }
    }
LAB_23e2eb4d9:
    plVar7 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eead1b8);
    if ((plVar7 == (longlong *)0x0) || (lVar12 = *plVar7, lVar12 == 0)) {
      FUN_23e915740(param_1,&uStack_68,_DAT_23eead1b8);
      uVar13 = uStack_68;
      plVar7 = plStack_58;
      uVar14 = uStack_60;
      goto LAB_23e2eb57c;
    }
  }
LAB_23e2eb38e:
  *(undefined4 *)(plVar4 + 5) = 0x71;
  plVar7 = (longlong *)FUN_23e915840(param_1,lVar12,_DAT_23eead1c0,plVar3);
  if (plVar7 != (longlong *)0x0) {
    if ((code *)plVar7[1] == PyLong_Type_exref) {
      plVar8 = (longlong *)
               (**(code **)(*(longlong *)(PyLong_Type_exref + 0x60) + 0x68))(plVar7,_DAT_23eead1c8);
      lVar10 = *plVar7 + -1;
      *plVar7 = lVar10;
      if (plVar8 != (longlong *)0x0) {
        if (lVar10 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        goto LAB_23e2eb3ef;
      }
      if (lVar10 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
    }
    else {
      plVar8 = (longlong *)FUN_23e8c0be0(plVar7);
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      if (plVar8 != (longlong *)0x0) {
LAB_23e2eb3ef:
        iVar6 = FUN_23a35f020(plVar8);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (iVar6 != -1) {
          pcVar9 = _Py_TrueStruct_exref;
          if (iVar6 == 0) {
            pcVar9 = _Py_FalseStruct_exref;
          }
          *(longlong *)pcVar9 = *(longlong *)pcVar9 + 1;
          lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar7 = *(longlong **)(lVar10 + 0x28);
          plVar4 = (longlong *)plVar7[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
          *(undefined4 *)(plVar7 + 8) = 0xffffffff;
          if (plVar4 != (longlong *)0x0) {
            plVar7[2] = 0;
            *plVar4 = *plVar4 + -1;
            if (*plVar4 == 0) {
              (**(code **)(plVar4[1] + 0x30))();
            }
          }
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          plVar7[0xf] = 0;
          *plVar2 = *plVar2 + -1;
          if (*plVar2 == 0) {
            (**(code **)(plVar2[1] + 0x30))(plVar2);
          }
          *plVar3 = *plVar3 + -1;
          if (*plVar3 != 0) {
            return pcVar9;
          }
          (**(code **)(plVar3[1] + 0x30))(plVar3);
          return pcVar9;
        }
      }
    }
  }
  plVar7 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar13 = *(undefined8 *)(param_1 + 0x60);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar14 = *(undefined8 *)(param_1 + 0x68);
LAB_23e2eb57c:
  plVar8 = DAT_23ed6a4f8;
  if (plVar7 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar7 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar7;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar11 = plVar8;
    }
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    plVar11[4] = 0x71ffffffff;
    lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar12 = plVar11[-1];
    puVar5 = *(undefined8 **)(lVar10 + 8);
    *puVar5 = plVar11 + -2;
    plVar11[-2] = lVar10;
    plVar11[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar10 + 8) = plVar11 + -2;
  }
  else {
    plVar11 = plVar7;
    if ((longlong *)plVar7[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar11 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar11;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar11 = plVar8;
      }
      plVar11[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      plVar11[4] = 0x71ffffffff;
      lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar12 = plVar11[-1];
      puVar5 = *(undefined8 **)(lVar10 + 8);
      *puVar5 = plVar11 + -2;
      plVar11[-2] = lVar10;
      plVar11[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar5;
      lVar12 = *plVar7;
      *(longlong **)(lVar10 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar7;
      if (lVar12 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5b14b,plVar2,plVar3);
  if (_DAT_23eeb0108 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeb0108 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar10 + 0x28);
  plVar4 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  plVar7[0xf] = 0;
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,uVar13,uVar14,plVar11);
  return (code *)0x0;
}
