/* ===== 23e11c180 telegram.handlers.menu_handler:36 ===== */
/* ghidra_name=FUN_23e11c180 entry=23e11c180 size=1686 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_23e11c180(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  code *pcVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  undefined4 uVar13;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar9 = _DAT_23eeab078;
  if (_DAT_23eeab078 == (longlong *)0x0) {
LAB_23e11c1b7:
    _DAT_23eeab078 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeab070,DAT_23eeab0a8,8);
  }
  else {
    lVar11 = *_DAT_23eeab078;
    if (1 < lVar11) {
      *_DAT_23eeab078 = lVar11 + -1;
      goto LAB_23e11c1b7;
    }
    if (_DAT_23eeab078[2] != 0) {
      *_DAT_23eeab078 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e11c1b7;
    }
  }
  plVar2 = _DAT_23eeab078;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eeab078 + 9;
  lVar1 = *(longlong *)(lVar11 + 8);
  _DAT_23eeab078[0xf] = lVar1;
  *(longlong **)(lVar11 + 8) = plVar9;
  if ((lVar1 != 0) &&
     (((*(char *)(lVar1 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar1 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar1 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar1 + 0x38))
       ) && (plVar2[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar1 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  lVar1 = _DAT_23eea8e58;
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  lVar11 = *(longlong *)(lVar1 + 0x20);
  if (*(char *)(lVar11 + 10) == '\0') {
    plVar9 = (longlong *)FUN_23a37a020(lVar1,_DAT_23eea8ed0);
    if (plVar9 == (longlong *)0x0) goto LAB_23e11c469;
    lVar11 = *plVar9;
LAB_23e11c7b8:
    if (lVar11 == 0) goto LAB_23e11c469;
  }
  else {
    iVar7 = *(int *)(lVar11 + 0xc);
    if (*(int *)(lVar11 + 0xc) == 0) {
      *(int *)(lVar11 + 0xc) = _DAT_23ec14c7c;
      iVar7 = _DAT_23ec14c7c;
      _DAT_23ec14c7c = _DAT_23ec14c7c + 1;
    }
    if (_DAT_23ec14c80 != iVar7) {
      _DAT_23ec14c80 = iVar7;
      _DAT_23eeab068 = FUN_23e8cbd60(lVar11,_DAT_23eea8ed0,*(undefined8 *)(_DAT_23eea8ed0 + 0x18));
    }
    if (-1 < _DAT_23eeab068) {
      lVar1 = lVar11 + 0x20 + (1L << (*(byte *)(lVar11 + 9) & 0x3f));
      if (*(longlong *)(lVar1 + 8 + _DAT_23eeab068 * 0x10) != 0) goto LAB_23e11c2a7;
      _DAT_23eeab068 = FUN_23e8cbd60(lVar11,_DAT_23eea8ed0,*(undefined8 *)(_DAT_23eea8ed0 + 0x18));
      if (-1 < _DAT_23eeab068) {
        lVar11 = *(longlong *)(lVar1 + 8 + _DAT_23eeab068 * 0x10);
        goto LAB_23e11c7b8;
      }
    }
LAB_23e11c469:
    plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eea8ed0);
    if ((plVar9 == (longlong *)0x0) || (*plVar9 == 0)) {
      uVar13 = 0x26;
      plVar8 = (longlong *)0x0;
      FUN_23e915740(param_1,&uStack_68,_DAT_23eea8ed0);
      plVar9 = plStack_58;
      uVar3 = uStack_68;
      uVar4 = uStack_60;
      plVar10 = DAT_23ed6a4f8;
      goto joined_r0x00023e11c5b5;
    }
  }
LAB_23e11c2a7:
  *(undefined4 *)(plVar2 + 5) = 0x26;
  plVar8 = (longlong *)FUN_23e91a870(param_1);
  if (plVar8 == (longlong *)0x0) {
    uVar3 = *(undefined8 *)(param_1 + 0x60);
    uVar4 = *(undefined8 *)(param_1 + 0x68);
    uVar13 = 0x26;
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar10 = DAT_23ed6a4f8;
  }
  else {
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eea8e70);
    lVar11 = _DAT_23eea8ed8;
    if (plVar9 != (longlong *)0x0) {
      *(undefined4 *)(plVar2 + 5) = 0x27;
      plVar10 = (longlong *)FUN_23e9186b0(param_1,plVar9,lVar11 + 0x18,_DAT_23eea8ee0);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (plVar10 != (longlong *)0x0) {
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        lVar11 = _DAT_23eea8ea0;
        *(undefined4 *)(plVar2 + 5) = 0x28;
        plVar9 = (longlong *)
                 FUN_23e915840(param_1,plVar8,_DAT_23eea8e98,*(undefined8 *)(lVar11 + 0x18));
        if (plVar9 == (longlong *)0x0) {
          uVar3 = *(undefined8 *)(param_1 + 0x60);
          uVar4 = *(undefined8 *)(param_1 + 0x68);
          uVar13 = 0x28;
          plVar9 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar10 = DAT_23ed6a4f8;
        }
        else {
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eea8ea8);
          lVar11 = _DAT_23eea8ee8;
          if (plVar9 != (longlong *)0x0) {
            *(undefined4 *)(plVar2 + 5) = 0x29;
            lVar11 = FUN_23e9186b0(param_1,plVar9,lVar11 + 0x18,_DAT_23eea8ef0);
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if (lVar11 != 0) {
              lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar9 = *(longlong **)(lVar1 + 0x28);
              plVar2 = (longlong *)plVar9[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar1 + 0x30);
              *(undefined4 *)(plVar9 + 8) = 0xffffffff;
              if (plVar2 != (longlong *)0x0) {
                plVar9[2] = 0;
                *plVar2 = *plVar2 + -1;
                if (*plVar2 == 0) {
                  (**(code **)(plVar2[1] + 0x30))();
                }
              }
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              plVar9[0xf] = 0;
              *plVar8 = *plVar8 + -1;
              if (*plVar8 != 0) {
                return lVar11;
              }
              (**(code **)(plVar8[1] + 0x30))(plVar8);
              return lVar11;
            }
          }
          plVar9 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar13 = 0x29;
          uVar3 = *(undefined8 *)(param_1 + 0x60);
          uVar4 = *(undefined8 *)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar10 = DAT_23ed6a4f8;
        }
        goto joined_r0x00023e11c5b5;
      }
    }
    uVar3 = *(undefined8 *)(param_1 + 0x60);
    uVar4 = *(undefined8 *)(param_1 + 0x68);
    uVar13 = 0x27;
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar10 = DAT_23ed6a4f8;
  }
joined_r0x00023e11c5b5:
  DAT_23ed6a4f8 = plVar10;
  if (plVar9 == (longlong *)0x0) {
    if (plVar10 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar10;
      *plVar10 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar12 = plVar10;
    }
    pcVar6 = _PyRuntime_exref;
    plVar12[2] = 0;
    plVar12[3] = (longlong)plVar2;
    *plVar2 = *plVar2 + 1;
    lVar11 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar13;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar1 = plVar12[-1];
    puVar5 = *(undefined8 **)(lVar11 + 8);
    *puVar5 = plVar12 + -2;
    plVar12[-2] = lVar11;
    plVar12[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar11 + 8) = plVar12 + -2;
  }
  else {
    plVar12 = plVar9;
    if ((longlong *)plVar9[3] != plVar2) {
      if (plVar10 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar10;
        *plVar10 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar12 = plVar10;
      }
      pcVar6 = _PyRuntime_exref;
      plVar12[3] = (longlong)plVar2;
      *plVar2 = *plVar2 + 1;
      lVar11 = *(longlong *)(pcVar6 + 0x1f8);
      *(undefined4 *)((longlong)plVar12 + 0x24) = uVar13;
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
      lVar1 = plVar12[-1];
      puVar5 = *(undefined8 **)(lVar11 + 8);
      *puVar5 = plVar12 + -2;
      plVar12[-2] = lVar11;
      plVar12[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar5;
      lVar1 = *plVar9;
      *(longlong **)(lVar11 + 8) = plVar12 + -2;
      plVar12[2] = (longlong)plVar9;
      if (lVar1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
    }
  }
  FUN_23e8bba40(plVar2,&DAT_23ec5a08d,plVar8);
  if (_DAT_23eeab078 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23eeab078 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar11 + 0x28);
  plVar2 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar2 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9[0xf] = 0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  FUN_23a33aa70(param_1,uVar3,uVar4,plVar12);
  return 0;
}
