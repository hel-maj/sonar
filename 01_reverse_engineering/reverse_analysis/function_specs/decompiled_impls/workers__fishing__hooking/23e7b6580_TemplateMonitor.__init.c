/* ===== 23e7b6580 workers.fishing.hooking:232 ===== */
/* ghidra_name=FUN_23e7b6580 entry=23e7b6580 size=3503 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e7b6580(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  int iVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined4 uVar13;
  undefined8 uVar15;
  longlong **pplStack_80;
  longlong *plStack_78;
  undefined8 uStack_70;
  longlong *plStack_68;
  undefined4 uVar14;
  
  plVar10 = _DAT_23eedaab0;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eedaab0 == (longlong *)0x0) {
LAB_23e7b65c3:
    _DAT_23eedaab0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaaa8,DAT_23eedab78,0x10);
  }
  else {
    lVar9 = *_DAT_23eedaab0;
    if (1 < lVar9) {
      *_DAT_23eedaab0 = lVar9 + -1;
      goto LAB_23e7b65c3;
    }
    if (_DAT_23eedaab0[2] != 0) {
      *_DAT_23eedaab0 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e7b65c3;
    }
  }
  plVar6 = _DAT_23eedaab0;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eedaab0 + 9;
  lVar3 = *(longlong *)(lVar9 + 8);
  _DAT_23eedaab0[0xf] = lVar3;
  *(longlong **)(lVar9 + 8) = plVar10;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar6[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar6 = *plVar6 + 1;
  uVar15 = _DAT_23eed7c30;
  *(undefined4 *)(plVar6 + 8) = 0;
  iVar8 = FUN_23e97a530(plVar1,uVar15);
  if (iVar8 != -1) {
    if (iVar8 != 1) {
LAB_23e7b6667:
      iVar8 = FUN_23e97a530(plVar1,_DAT_23eed7c60);
      if (iVar8 == -1) {
LAB_23e7b70a0:
        plVar10 = *(longlong **)(param_1 + 0x60);
        uVar15 = *(undefined8 *)(param_1 + 0x68);
        uVar14 = 0xec;
        plStack_68 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar12 = DAT_23ed6a4f8;
        goto joined_r0x00023e7b6fdc;
      }
      if (iVar8 == 1) {
        iVar8 = FUN_23e97a530(plVar2,_DAT_23eed7c68);
        plVar10 = _DAT_23eed7c70;
        if (iVar8 == -1) goto LAB_23e7b70a0;
        if (iVar8 != 1) goto LAB_23e7b6688;
        lVar9 = *(longlong *)(param_1 + 0x10);
        plVar12 = *(longlong **)(lVar9 + 0xe30);
        if (plVar12 == (longlong *)0x0) {
          plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
        }
        else {
          lVar3 = plVar12[3];
          *(int *)(lVar9 + 0xec4) = *(int *)(lVar9 + 0xec4) + -1;
          *(longlong *)(lVar9 + 0xe30) = lVar3;
          *plVar12 = 1;
        }
        pcVar7 = _PyRuntime_exref;
        plVar12[6] = 0;
        *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
        lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar7 + 0x1f8) + 0x10) + 0x2e8);
        lVar3 = plVar12[-1];
        puVar4 = *(undefined8 **)(lVar9 + 8);
        *puVar4 = plVar12 + -2;
        plVar12[-2] = lVar9;
        plVar12[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
        *(longlong **)(lVar9 + 8) = plVar12 + -2;
        *plVar10 = *plVar10 + 1;
        plVar12[3] = (longlong)plVar10;
        plVar10 = (longlong *)FUN_23e8de720();
        uVar15 = _DAT_23eed7c78;
        if (plVar10 == (longlong *)0x0) {
LAB_23e7b6f82:
          FUN_23e915740(param_1,&plStack_78,uVar15);
          uVar15 = uStack_70;
          plVar10 = plStack_78;
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          uVar14 = 0xed;
          plVar12 = DAT_23ed6a4f8;
          goto joined_r0x00023e7b6fdc;
        }
        *plVar10 = *plVar10 + 1;
        plVar12[4] = (longlong)plVar10;
        plVar10 = (longlong *)FUN_23e8de5d0();
        uVar15 = _DAT_23eed7c80;
        if (plVar10 == (longlong *)0x0) goto LAB_23e7b6f82;
LAB_23e7b689b:
        *plVar10 = *plVar10 + 1;
        plVar12[5] = (longlong)plVar10;
        plVar10 = _DAT_23eed7b50;
        *_DAT_23eed7b50 = *_DAT_23eed7b50 + 1;
        plVar12[6] = (longlong)plVar10;
LAB_23e7b6aed:
        lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar10 = *(longlong **)(lVar9 + 0x28);
        plVar6 = (longlong *)plVar10[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
        *(undefined4 *)(plVar10 + 8) = 0xffffffff;
        if (plVar6 != (longlong *)0x0) {
          plVar10[2] = 0;
          *plVar6 = *plVar6 + -1;
          if (*plVar6 == 0) {
            (**(code **)(plVar6[1] + 0x30))();
          }
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        plVar10[0xf] = 0;
        *plVar1 = *plVar1 + -1;
        if (*plVar1 == 0) {
          (**(code **)(plVar1[1] + 0x30))(plVar1);
        }
        *plVar2 = *plVar2 + -1;
        if (*plVar2 != 0) {
          return plVar12;
        }
        (**(code **)(plVar2[1] + 0x30))(plVar2);
        return plVar12;
      }
LAB_23e7b6688:
      iVar8 = FUN_23e97c2c0(plVar1,_DAT_23eed7c88);
      plVar10 = _DAT_23eed7c90;
      if (iVar8 == -1) {
        plVar10 = *(longlong **)(param_1 + 0x60);
        uVar15 = *(undefined8 *)(param_1 + 0x68);
        uVar14 = 0xf0;
        plStack_68 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar12 = DAT_23ed6a4f8;
        goto joined_r0x00023e7b6fdc;
      }
      lVar9 = *(longlong *)(param_1 + 0x10);
      plVar11 = *(longlong **)(lVar9 + 0xe38);
      if (iVar8 == 1) {
        if (plVar11 == (longlong *)0x0) {
          plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,5);
        }
        else {
          lVar3 = plVar11[3];
          *(int *)(lVar9 + 0xec8) = *(int *)(lVar9 + 0xec8) + -1;
          *(longlong *)(lVar9 + 0xe38) = lVar3;
          *plVar11 = 1;
        }
        pcVar7 = _PyRuntime_exref;
        *(undefined1 (*) [16])(plVar11 + 4) = (undefined1  [16])0x0;
        lVar9 = *(longlong *)(pcVar7 + 0x1f8);
        *(undefined1 (*) [16])(plVar11 + 6) = (undefined1  [16])0x0;
        lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
        lVar3 = plVar11[-1];
        puVar4 = *(undefined8 **)(lVar9 + 8);
        *puVar4 = plVar11 + -2;
        plVar11[-2] = lVar9;
        plVar11[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
        *(longlong **)(lVar9 + 8) = plVar11 + -2;
        *plVar10 = *plVar10 + 1;
        plVar11[3] = (longlong)plVar10;
        uVar15 = DAT_23ed6cd28;
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar10 == (longlong *)0x0) goto LAB_23e7b72c0;
          *plVar10 = *plVar10 + 1;
          DAT_23ed6a4c0 = plVar10;
        }
        uStack_70 = uVar15;
        plStack_78 = plVar1;
        lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_78);
        if (lVar9 != 0) {
          plVar11[4] = lVar9;
          plVar12 = _DAT_23eed7c98;
          plVar10 = DAT_23ed6a4c0;
          *_DAT_23eed7c98 = *_DAT_23eed7c98 + 1;
          plVar11[5] = (longlong)plVar12;
          uVar15 = DAT_23ed6cd28;
          if (plVar10 == (longlong *)0x0) {
            plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar10 == (longlong *)0x0) goto LAB_23e7b72c0;
            *plVar10 = *plVar10 + 1;
            DAT_23ed6a4c0 = plVar10;
          }
          pplStack_80 = &plStack_78;
          uStack_70 = uVar15;
          plStack_78 = plVar2;
          lVar9 = FUN_23e94ed00(param_1,plVar10,pplStack_80);
          if (lVar9 == 0) goto LAB_23e7b70d0;
          plVar11[6] = lVar9;
          plVar10 = _DAT_23eed7ca0;
          *_DAT_23eed7ca0 = *_DAT_23eed7ca0 + 1;
          plVar11[7] = (longlong)plVar10;
          lVar9 = PyUnicode_Join(DAT_23ed6cd28,plVar11);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (lVar9 != 0) {
            lVar3 = *(longlong *)(param_1 + 0x10);
            plVar12 = *(longlong **)(lVar3 + 0xe30);
            if (plVar12 == (longlong *)0x0) {
              plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
            }
            else {
              lVar5 = plVar12[3];
              *(int *)(lVar3 + 0xec4) = *(int *)(lVar3 + 0xec4) + -1;
              *(longlong *)(lVar3 + 0xe30) = lVar5;
              *plVar12 = 1;
            }
            lVar3 = *(longlong *)(pcVar7 + 0x1f8);
            plVar12[6] = 0;
            *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
            lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x2e8);
            lVar5 = plVar12[-1];
            puVar4 = *(undefined8 **)(lVar3 + 8);
            *puVar4 = plVar12 + -2;
            plVar12[-2] = lVar3;
            plVar12[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar4;
            *(longlong **)(lVar3 + 8) = plVar12 + -2;
            plVar12[3] = lVar9;
            plVar10 = (longlong *)FUN_23e8de9c0();
            uVar15 = _DAT_23eed7c48;
            if (plVar10 != (longlong *)0x0) {
              *plVar10 = *plVar10 + 1;
              plVar12[4] = (longlong)plVar10;
              plVar10 = (longlong *)FUN_23e8de870();
              uVar15 = _DAT_23eed7c50;
              if (plVar10 != (longlong *)0x0) goto LAB_23e7b6ad6;
            }
            FUN_23e915740(param_1,pplStack_80,uVar15);
            uVar15 = uStack_70;
            plVar10 = plStack_78;
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            uVar14 = 0xf1;
            plVar12 = DAT_23ed6a4f8;
            goto joined_r0x00023e7b6fdc;
          }
          goto LAB_23e7b72d8;
        }
LAB_23e7b70d0:
        plVar10 = *(longlong **)(param_1 + 0x60);
        uVar15 = *(undefined8 *)(param_1 + 0x68);
        uVar14 = 0xf1;
        uVar13 = 0xf1;
        plStack_68 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar11 = *plVar11 + -1;
        lVar9 = *plVar11;
      }
      else {
        if (plVar11 == (longlong *)0x0) {
          plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,5);
        }
        else {
          lVar3 = plVar11[3];
          *(int *)(lVar9 + 0xec8) = *(int *)(lVar9 + 0xec8) + -1;
          *(longlong *)(lVar9 + 0xe38) = lVar3;
          *plVar11 = 1;
        }
        pcVar7 = _PyRuntime_exref;
        *(undefined1 (*) [16])(plVar11 + 4) = (undefined1  [16])0x0;
        lVar9 = *(longlong *)(pcVar7 + 0x1f8);
        *(undefined1 (*) [16])(plVar11 + 6) = (undefined1  [16])0x0;
        lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
        lVar3 = plVar11[-1];
        puVar4 = *(undefined8 **)(lVar9 + 8);
        *puVar4 = plVar11 + -2;
        plVar11[-2] = lVar9;
        plVar11[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
        *(longlong **)(lVar9 + 8) = plVar11 + -2;
        *plVar10 = *plVar10 + 1;
        plVar11[3] = (longlong)plVar10;
        uVar15 = DAT_23ed6cd28;
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar10 != (longlong *)0x0) {
            *plVar10 = *plVar10 + 1;
            DAT_23ed6a4c0 = plVar10;
            goto LAB_23e7b675b;
          }
LAB_23e7b72c0:
          PyErr_PrintEx(0,0);
          Py_Exit(1);
LAB_23e7b72d8:
          plVar10 = *(longlong **)(param_1 + 0x60);
          uVar15 = *(undefined8 *)(param_1 + 0x68);
          uVar14 = 0xf1;
          plStack_68 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar12 = DAT_23ed6a4f8;
          goto joined_r0x00023e7b6fdc;
        }
LAB_23e7b675b:
        uStack_70 = uVar15;
        plStack_78 = plVar1;
        lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_78);
        if (lVar9 != 0) {
          plVar11[4] = lVar9;
          plVar12 = _DAT_23eed7c98;
          plVar10 = DAT_23ed6a4c0;
          *_DAT_23eed7c98 = *_DAT_23eed7c98 + 1;
          plVar11[5] = (longlong)plVar12;
          uVar15 = DAT_23ed6cd28;
          if (plVar10 == (longlong *)0x0) {
            plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar10 == (longlong *)0x0) goto LAB_23e7b72c0;
            *plVar10 = *plVar10 + 1;
            DAT_23ed6a4c0 = plVar10;
          }
          uStack_70 = uVar15;
          plStack_78 = plVar2;
          lVar9 = FUN_23e94ed00(param_1,plVar10,&plStack_78);
          if (lVar9 != 0) {
            plVar11[6] = lVar9;
            plVar10 = _DAT_23eed7ca8;
            *_DAT_23eed7ca8 = *_DAT_23eed7ca8 + 1;
            plVar11[7] = (longlong)plVar10;
            lVar9 = PyUnicode_Join(DAT_23ed6cd28,plVar11);
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if (lVar9 == 0) {
              plVar10 = *(longlong **)(param_1 + 0x60);
              uVar15 = *(undefined8 *)(param_1 + 0x68);
              plStack_68 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar12 = DAT_23ed6a4f8;
              uVar14 = 0xf3;
              goto joined_r0x00023e7b6fdc;
            }
            lVar3 = *(longlong *)(param_1 + 0x10);
            plVar12 = *(longlong **)(lVar3 + 0xe30);
            if (plVar12 == (longlong *)0x0) {
              plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
            }
            else {
              lVar5 = plVar12[3];
              *(int *)(lVar3 + 0xec4) = *(int *)(lVar3 + 0xec4) + -1;
              *(longlong *)(lVar3 + 0xe30) = lVar5;
              *plVar12 = 1;
            }
            lVar3 = *(longlong *)(pcVar7 + 0x1f8);
            plVar12[6] = 0;
            *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
            lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x2e8);
            lVar5 = plVar12[-1];
            puVar4 = *(undefined8 **)(lVar3 + 8);
            *puVar4 = plVar12 + -2;
            plVar12[-2] = lVar3;
            plVar12[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar4;
            *(longlong **)(lVar3 + 8) = plVar12 + -2;
            plVar12[3] = lVar9;
            plVar10 = (longlong *)FUN_23e8de720();
            uVar15 = _DAT_23eed7c78;
            if (plVar10 != (longlong *)0x0) {
              *plVar10 = *plVar10 + 1;
              plVar12[4] = (longlong)plVar10;
              plVar10 = (longlong *)FUN_23e8de5d0();
              uVar15 = _DAT_23eed7c80;
              if (plVar10 != (longlong *)0x0) goto LAB_23e7b689b;
            }
            FUN_23e915740(param_1,&plStack_78,uVar15);
            uVar15 = uStack_70;
            plVar10 = plStack_78;
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            plVar12 = DAT_23ed6a4f8;
            uVar14 = 0xf3;
            goto joined_r0x00023e7b6fdc;
          }
        }
        plVar10 = *(longlong **)(param_1 + 0x60);
        uVar15 = *(undefined8 *)(param_1 + 0x68);
        uVar14 = 0xf3;
        uVar13 = 0xf3;
        plStack_68 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar11 = *plVar11 + -1;
        lVar9 = *plVar11;
      }
      plVar12 = DAT_23ed6a4f8;
      if (lVar9 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
        plVar12 = DAT_23ed6a4f8;
        uVar14 = uVar13;
      }
      goto joined_r0x00023e7b6fdc;
    }
    iVar8 = FUN_23e97a530(plVar2,_DAT_23eed7c38);
    plVar10 = _DAT_23eed7c40;
    if (iVar8 != -1) {
      if (iVar8 != 1) goto LAB_23e7b6667;
      lVar9 = *(longlong *)(param_1 + 0x10);
      plVar12 = *(longlong **)(lVar9 + 0xe30);
      if (plVar12 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
      }
      else {
        lVar3 = plVar12[3];
        *(int *)(lVar9 + 0xec4) = *(int *)(lVar9 + 0xec4) + -1;
        *(longlong *)(lVar9 + 0xe30) = lVar3;
        *plVar12 = 1;
      }
      pcVar7 = _PyRuntime_exref;
      plVar12[6] = 0;
      *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
      lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar7 + 0x1f8) + 0x10) + 0x2e8);
      lVar3 = plVar12[-1];
      puVar4 = *(undefined8 **)(lVar9 + 8);
      *puVar4 = plVar12 + -2;
      plVar12[-2] = lVar9;
      plVar12[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
      *(longlong **)(lVar9 + 8) = plVar12 + -2;
      *plVar10 = *plVar10 + 1;
      plVar12[3] = (longlong)plVar10;
      plVar10 = (longlong *)FUN_23e8de9c0();
      uVar15 = _DAT_23eed7c48;
      if (plVar10 != (longlong *)0x0) {
        *plVar10 = *plVar10 + 1;
        plVar12[4] = (longlong)plVar10;
        plVar10 = (longlong *)FUN_23e8de870();
        uVar15 = _DAT_23eed7c50;
        if (plVar10 != (longlong *)0x0) {
LAB_23e7b6ad6:
          *plVar10 = *plVar10 + 1;
          plVar12[5] = (longlong)plVar10;
          plVar10 = _DAT_23eed7c58;
          *_DAT_23eed7c58 = *_DAT_23eed7c58 + 1;
          plVar12[6] = (longlong)plVar10;
          goto LAB_23e7b6aed;
        }
      }
      FUN_23e915740(param_1,&plStack_78,uVar15);
      uVar15 = uStack_70;
      plVar10 = plStack_78;
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      uVar14 = 0xeb;
      plVar12 = DAT_23ed6a4f8;
      goto joined_r0x00023e7b6fdc;
    }
  }
  plStack_68 = *(longlong **)(param_1 + 0x70);
  plVar10 = *(longlong **)(param_1 + 0x60);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar15 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar12 = DAT_23ed6a4f8;
  uVar14 = 0xea;
joined_r0x00023e7b6fdc:
  DAT_23ed6a4f8 = plVar12;
  if (plStack_68 == (longlong *)0x0) {
    if (plVar12 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar12;
      *plVar12 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar7 = _PyRuntime_exref;
    plVar12[2] = 0;
    plVar12[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    lVar9 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar14;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar3 = plVar12[-1];
    puVar4 = *(undefined8 **)(lVar9 + 8);
    *puVar4 = plVar12 + -2;
    plVar12[-2] = lVar9;
    plVar12[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar9 + 8) = plVar12 + -2;
    plVar11 = plVar12;
  }
  else {
    plVar11 = plStack_68;
    if ((longlong *)plStack_68[3] != plVar6) {
      if (plVar12 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar12;
        *plVar12 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar7 = _PyRuntime_exref;
      plVar12[3] = (longlong)plVar6;
      *plVar6 = *plVar6 + 1;
      lVar9 = *(longlong *)(pcVar7 + 0x1f8);
      *(undefined4 *)((longlong)plVar12 + 0x24) = uVar14;
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
      lVar3 = plVar12[-1];
      puVar4 = *(undefined8 **)(lVar9 + 8);
      *puVar4 = plVar12 + -2;
      plVar12[-2] = lVar9;
      plVar12[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
      lVar3 = *plStack_68;
      *(longlong **)(lVar9 + 8) = plVar12 + -2;
      plVar12[2] = (longlong)plStack_68;
      plVar11 = plVar12;
      if (lVar3 == 0) {
        (**(code **)(plStack_68[1] + 0x30))(plStack_68);
      }
    }
  }
  FUN_23e8bba40(plVar6,&DAT_23ec5dd15,plVar1,plVar2);
  if (_DAT_23eedaab0 == plVar6) {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    _DAT_23eedaab0 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar9 + 0x28);
  plVar12 = (longlong *)plVar6[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar12 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar6[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,plVar10,uVar15,plVar11);
  return (longlong *)0x0;
}
