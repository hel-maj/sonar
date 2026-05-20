/* ===== 23aaa2cd0 __main__:79 ===== */
/* ghidra_name=FUN_23aaa2cd0 entry=23aaa2cd0 size=9634 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

longlong * FUN_23aaa2cd0(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  code *pcVar4;
  int iVar5;
  code *pcVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  code *pcVar13;
  longlong *plVar14;
  longlong *plVar15;
  code *pcVar16;
  code *pcVar17;
  longlong lVar18;
  code *local_d8;
  undefined4 local_d0;
  code *local_c8;
  code *local_c0;
  longlong *local_a8;
  code *pcStack_a0;
  undefined1 local_98 [16];
  code *local_88 [2];
  longlong *local_78;
  code *pcStack_70;
  code *local_68;
  
  plVar8 = _DAT_23ed90cf0;
  if (_DAT_23ed90cf0 == (longlong *)0x0) {
LAB_23aaa2d12:
    _DAT_23ed90cf0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ed90ce8,DAT_23ed90d18,0x10);
  }
  else {
    lVar7 = *_DAT_23ed90cf0;
    if (1 < lVar7) {
      *_DAT_23ed90cf0 = lVar7 + -1;
      goto LAB_23aaa2d12;
    }
    if (_DAT_23ed90cf0[2] != 0) {
      *_DAT_23ed90cf0 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23aaa2d12;
    }
  }
  plVar3 = _DAT_23ed90cf0;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23ed90cf0 + 9;
  lVar18 = *(longlong *)(lVar7 + 8);
  _DAT_23ed90cf0[0xf] = lVar18;
  *(longlong **)(lVar7 + 8) = plVar8;
  if ((lVar18 != 0) &&
     (((*(char *)(lVar18 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar18 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar18 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar18 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar18 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  if ((DAT_23ed6a210 == 0) &&
     (DAT_23ed6a210 = PyImport_ImportModule(&DAT_23ec31700), DAT_23ed6a210 == 0))
  goto LAB_23aaa33db;
  pcVar16 = _Py_FalseStruct_exref;
  pcVar6 = (code *)FUN_23e8bbbe0(param_1,DAT_23ed6a210,_DAT_23ed8fb88,_Py_FalseStruct_exref);
  if (pcVar6 == (code *)0x0) {
    local_c8 = *(code **)(param_1 + 0x70);
    plVar8 = *(longlong **)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar16 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (local_c8 == (code *)0x0) {
      plVar9 = (longlong *)0x0;
      iVar5 = 0x55;
      local_d8 = _PyRuntime_exref;
      goto LAB_23aaa40f0;
    }
    if (plVar3 == *(longlong **)(local_c8 + 0x18)) {
LAB_23aaa35ff:
      plVar11 = (longlong *)0x0;
      pcVar17 = pcVar16;
      pcVar13 = local_c8;
      goto LAB_23aaa34f0;
    }
    plVar11 = (longlong *)0x0;
    iVar5 = 0x55;
    local_d8 = _PyRuntime_exref;
LAB_23aaa3450:
    pcVar13 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar13 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar17 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar17;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar13 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar7 = *(longlong *)(local_d8 + 0x1f8);
    *(int *)(pcVar13 + 0x24) = iVar5;
    *(undefined4 *)(pcVar13 + 0x20) = 0xffffffff;
    lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
    lVar18 = *(longlong *)(pcVar13 + -8);
    plVar9 = *(longlong **)(lVar7 + 8);
    *plVar9 = (longlong)(pcVar13 + -0x10);
    *(longlong *)(pcVar13 + -0x10) = lVar7;
    *(ulonglong *)(pcVar13 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)plVar9;
    lVar18 = *(longlong *)local_c8;
    *(code **)(lVar7 + 8) = pcVar13 + -0x10;
    *(code **)(pcVar13 + 0x10) = local_c8;
    pcVar17 = pcVar16;
    if (lVar18 == 0) {
      (**(code **)(*(longlong *)(local_c8 + 8) + 0x30))(local_c8);
    }
  }
  else {
    iVar5 = FUN_23a35f020(pcVar6);
    if (iVar5 == -1) {
      plVar8 = *(longlong **)(param_1 + 0x60);
      pcVar16 = *(code **)(param_1 + 0x68);
      local_c8 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(longlong *)pcVar6 = *(longlong *)pcVar6 + -1;
      if (*(longlong *)pcVar6 == 0) {
        (**(code **)(*(longlong *)(pcVar6 + 8) + 0x30))(pcVar6);
        if (local_c8 != (code *)0x0) goto LAB_23aaa3635;
      }
      else if (local_c8 != (code *)0x0) {
        plVar9 = *(longlong **)(local_c8 + 0x18);
        goto joined_r0x00023aaa42fd;
      }
LAB_23aaa40d3:
      plVar9 = (longlong *)0x0;
      pcVar6 = (code *)0x0;
      iVar5 = 0x55;
      local_d8 = _PyRuntime_exref;
    }
    else {
      if (iVar5 != 1) {
        *(longlong *)pcVar6 = *(longlong *)pcVar6 + -1;
        if (*(longlong *)pcVar6 == 0) {
          (**(code **)(*(longlong *)(pcVar6 + 8) + 0x30))(pcVar6);
        }
        iVar5 = PySequence_Contains(DAT_23ed8fb58,DAT_23ed6cdd0);
        if (iVar5 == -1) {
          local_c8 = *(code **)(param_1 + 0x70);
          plVar8 = *(longlong **)(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar16 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (local_c8 == (code *)0x0) goto LAB_23aaa40d3;
LAB_23aaa3635:
          plVar9 = *(longlong **)(local_c8 + 0x18);
joined_r0x00023aaa42fd:
          if (plVar9 == plVar3) {
            pcVar6 = (code *)0x0;
            plVar11 = (longlong *)0x0;
            pcVar17 = pcVar16;
            pcVar13 = local_c8;
            goto LAB_23aaa34f0;
          }
          plVar11 = (longlong *)0x0;
          pcVar6 = (code *)0x0;
          iVar5 = 0x55;
          local_d8 = _PyRuntime_exref;
          goto LAB_23aaa3450;
        }
        pcVar6 = pcVar16;
        if (iVar5 == 1) {
          pcVar6 = _Py_TrueStruct_exref;
        }
        *(longlong *)pcVar6 = *(longlong *)pcVar6 + 1;
      }
      iVar5 = FUN_23a35f020(pcVar6);
      if (iVar5 != -1) {
        if (iVar5 == 0) {
          lVar7 = FUN_23ebc0e20();
          if (lVar7 == 0) {
            FUN_23e915740(param_1,&local_78,DAT_23ed6cd80);
            plVar9 = (longlong *)0x0;
            pcVar16 = pcStack_70;
            plVar8 = local_78;
            if (local_68 == (code *)0x0) {
LAB_23aaa4d18:
              iVar5 = 0x67;
              local_d8 = _PyRuntime_exref;
              goto LAB_23aaa40f0;
            }
            plVar11 = (longlong *)0x0;
            local_c8 = local_68;
            if (*(longlong **)(local_68 + 0x18) == plVar3) {
              plVar11 = (longlong *)0x0;
              pcVar17 = pcStack_70;
              pcVar13 = local_68;
              goto LAB_23aaa34f0;
            }
LAB_23aaa445f:
            iVar5 = 0x67;
            local_d8 = _PyRuntime_exref;
            goto LAB_23aaa3450;
          }
          plVar8 = (longlong *)FUN_23e937070(param_1,lVar7);
          if (plVar8 == (longlong *)0x0) {
            local_c8 = *(code **)(param_1 + 0x70);
            plVar8 = *(longlong **)(param_1 + 0x60);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar16 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (local_c8 == (code *)0x0) {
              iVar5 = 0x67;
              local_d8 = _PyRuntime_exref;
              plVar9 = (longlong *)0x0;
              goto LAB_23aaa40f0;
            }
            plVar11 = (longlong *)0x0;
            if (plVar3 == *(longlong **)(local_c8 + 0x18)) goto LAB_23aaa35ff;
            goto LAB_23aaa445f;
          }
          plVar9 = (longlong *)FUN_23e936ef0(param_1,plVar8);
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          plVar11 = plVar9;
          if (plVar9 == (longlong *)0x0) {
            local_c8 = *(code **)(param_1 + 0x70);
            plVar8 = *(longlong **)(param_1 + 0x60);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar16 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (local_c8 == (code *)0x0) goto LAB_23aaa4d18;
            pcVar17 = pcVar16;
            pcVar13 = local_c8;
            if (plVar3 == *(longlong **)(local_c8 + 0x18)) goto LAB_23aaa34f0;
            goto LAB_23aaa445f;
          }
          lVar7 = FUN_23ebc0cf0();
          if (lVar7 == 0) {
            FUN_23e915740(param_1,&local_78,DAT_23ed8fba8);
            plVar8 = local_78;
            pcVar16 = pcStack_70;
            local_c8 = local_68;
joined_r0x00023aaa4a42:
            local_d8 = _PyRuntime_exref;
            if (local_c8 != (code *)0x0) {
              pcVar17 = pcVar16;
              pcVar13 = local_c8;
              if (plVar3 == *(longlong **)(local_c8 + 0x18)) goto LAB_23aaa34f0;
              iVar5 = 0x68;
              goto LAB_23aaa3450;
            }
            iVar5 = 0x68;
            goto LAB_23aaa40f0;
          }
          plVar10 = (longlong *)FUN_23e8bc2f0(lVar7,DAT_23ed8fbb0);
          plVar8 = _DAT_23ed8fc38;
          if (plVar10 == (longlong *)0x0) {
            local_c8 = *(code **)(param_1 + 0x70);
            plVar8 = *(longlong **)(param_1 + 0x60);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar16 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto joined_r0x00023aaa4a42;
          }
          lVar7 = *(longlong *)(param_1 + 0x10);
          plVar11 = *(longlong **)(lVar7 + 0xe20);
          if (plVar11 == (longlong *)0x0) {
            plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar18 = plVar11[3];
            *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
            *(longlong *)(lVar7 + 0xe20) = lVar18;
            *plVar11 = 1;
          }
          local_d8 = _PyRuntime_exref;
          plVar11[4] = 0;
          lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(local_d8 + 0x1f8) + 0x10) + 0x2e8);
          lVar18 = plVar11[-1];
          puVar2 = *(undefined8 **)(lVar7 + 8);
          *puVar2 = plVar11 + -2;
          plVar11[-2] = lVar7;
          plVar11[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
          *(longlong **)(lVar7 + 8) = plVar11 + -2;
          plVar14 = DAT_23ed6a4c0;
          *plVar8 = *plVar8 + 1;
          plVar11[3] = (longlong)plVar8;
          pcVar16 = DAT_23ed6cd28;
          if (plVar14 == (longlong *)0x0) {
            plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            plVar12 = plVar9;
            if (plVar14 != (longlong *)0x0) {
              *plVar14 = *plVar14 + 1;
              DAT_23ed6a4c0 = plVar14;
              goto LAB_23aaa2f72;
            }
            goto LAB_23aaa4f26;
          }
LAB_23aaa2f72:
          pcStack_70 = pcVar16;
          local_78 = plVar9;
          lVar7 = FUN_23e94ed00(param_1,plVar14,&local_78);
          if (lVar7 == 0) {
            plVar8 = *(longlong **)(param_1 + 0x60);
            pcVar16 = *(code **)(param_1 + 0x68);
            local_c8 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
              if (local_c8 == (code *)0x0) goto LAB_23aaa4c75;
              iVar5 = 0x68;
              plVar10 = *(longlong **)(local_c8 + 0x18);
              goto joined_r0x00023aaa44c6;
            }
            iVar5 = 0x68;
joined_r0x00023aaa5001:
            if (local_c8 != (code *)0x0) goto LAB_23aaa4587;
            goto LAB_23aaa40f0;
          }
          plVar11[4] = lVar7;
          plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (plVar8 == (longlong *)0x0) {
            plVar8 = *(longlong **)(param_1 + 0x60);
            pcVar16 = *(code **)(param_1 + 0x68);
            local_c8 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
              goto joined_r0x00023aaa4c6f;
            }
            iVar5 = 0x68;
            if (local_c8 == (code *)0x0) goto LAB_23aaa40f0;
LAB_23aaa4e60:
            plVar10 = *(longlong **)(local_c8 + 0x18);
          }
          else {
            *(undefined4 *)(plVar3 + 5) = 0x68;
            plVar11 = (longlong *)FUN_23e914090(param_1,plVar10,plVar8);
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            if (plVar11 != (longlong *)0x0) {
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              goto LAB_23aaa3008;
            }
            local_c8 = *(code **)(param_1 + 0x70);
            plVar8 = *(longlong **)(param_1 + 0x60);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar16 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
joined_r0x00023aaa4c6f:
            if (local_c8 == (code *)0x0) {
LAB_23aaa4c75:
              iVar5 = 0x68;
              goto LAB_23aaa40f0;
            }
            iVar5 = 0x68;
            plVar10 = *(longlong **)(local_c8 + 0x18);
          }
        }
        else {
          lVar7 = *(longlong *)(DAT_23ed8fb58 + 0x20);
          if (*(char *)(lVar7 + 10) == '\0') {
            plVar8 = (longlong *)FUN_23a37a020(DAT_23ed8fb58,DAT_23ed6cdd0);
            if (plVar8 == (longlong *)0x0) goto LAB_23aaa3348;
            lVar18 = *plVar8;
LAB_23aaa46f8:
            if (lVar18 == 0) goto LAB_23aaa3348;
LAB_23aaa310d:
            plVar9 = (longlong *)FUN_23e8bc2f0(lVar18,_DAT_23ed8fbf8);
            local_d8 = _PyRuntime_exref;
            plVar11 = plVar9;
            if (plVar9 == (longlong *)0x0) {
              pcVar17 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar8 = *(longlong **)(param_1 + 0x60);
              local_d0 = 0x5b;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcVar13 = *(code **)(param_1 + 0x68);
              goto LAB_23aaa368a;
            }
            lVar7 = FUN_23ebc0cf0();
            if (lVar7 == 0) {
              FUN_23e915740(param_1,&local_78,DAT_23ed8fba8);
              local_d0 = 0x5c;
              local_d8 = _PyRuntime_exref;
              pcVar17 = local_68;
              plVar8 = local_78;
              pcVar13 = pcStack_70;
              goto LAB_23aaa368a;
            }
            plVar10 = (longlong *)FUN_23e8bc2f0(lVar7,DAT_23ed8fbb0);
            plVar8 = _DAT_23ed8fc00;
            if (plVar10 == (longlong *)0x0) {
              local_d8 = _PyRuntime_exref;
              plVar8 = *(longlong **)(param_1 + 0x60);
              local_d0 = 0x5c;
              pcVar17 = *(code **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar13 = *(code **)(param_1 + 0x68);
              goto LAB_23aaa368a;
            }
            lVar7 = *(longlong *)(param_1 + 0x10);
            plVar14 = *(longlong **)(lVar7 + 0xe20);
            if (plVar14 == (longlong *)0x0) {
              plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
            }
            else {
              lVar18 = plVar14[3];
              *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
              *(longlong *)(lVar7 + 0xe20) = lVar18;
              *plVar14 = 1;
            }
            local_d8 = _PyRuntime_exref;
            plVar14[4] = 0;
            lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(local_d8 + 0x1f8) + 0x10) + 0x2e8);
            lVar18 = plVar14[-1];
            puVar2 = *(undefined8 **)(lVar7 + 8);
            *puVar2 = plVar14 + -2;
            plVar14[-2] = lVar7;
            plVar14[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
            *(longlong **)(lVar7 + 8) = plVar14 + -2;
            plVar15 = DAT_23ed6a4c0;
            *plVar8 = *plVar8 + 1;
            plVar14[3] = (longlong)plVar8;
            pcVar17 = DAT_23ed6cd28;
            if (plVar15 == (longlong *)0x0) {
              plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              plVar12 = plVar9;
              if (plVar15 != (longlong *)0x0) {
                *plVar15 = *plVar15 + 1;
                DAT_23ed6a4c0 = plVar15;
                goto LAB_23aaa3207;
              }
LAB_23aaa4f26:
              PyErr_PrintEx(0,0);
              Py_Exit(1);
              plVar9 = plVar12;
LAB_23aaa4f39:
              FUN_23e915740(param_1,&local_78,DAT_23ed8fba8);
              local_c8 = local_68;
              plVar8 = local_78;
              pcVar16 = pcStack_70;
joined_r0x00023aaa510a:
              if (local_c8 != (code *)0x0) {
                iVar5 = 0x62;
                plVar10 = *(longlong **)(local_c8 + 0x18);
                goto joined_r0x00023aaa44c6;
              }
            }
            else {
LAB_23aaa3207:
              pcStack_70 = pcVar17;
              local_78 = plVar9;
              lVar7 = FUN_23e94ed00(param_1,plVar15,&local_78);
              if (lVar7 == 0) {
                plVar8 = *(longlong **)(param_1 + 0x60);
                pcVar13 = *(code **)(param_1 + 0x68);
                pcVar17 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                *plVar14 = *plVar14 + -1;
                local_d0 = 0x5c;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                  local_d0 = 0x5c;
                }
                goto LAB_23aaa368a;
              }
              plVar14[4] = lVar7;
              local_c0 = PyUnicode_Join_exref;
              plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              if (plVar8 == (longlong *)0x0) {
                plVar8 = *(longlong **)(param_1 + 0x60);
                pcVar13 = *(code **)(param_1 + 0x68);
                pcVar17 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                local_d0 = 0x5c;
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                  local_d0 = 0x5c;
                }
                goto LAB_23aaa368a;
              }
              *(undefined4 *)(plVar3 + 5) = 0x5c;
              plVar14 = (longlong *)FUN_23e914090(param_1,plVar10,plVar8);
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              if (plVar14 == (longlong *)0x0) {
                plVar8 = *(longlong **)(param_1 + 0x60);
                pcVar17 = *(code **)(param_1 + 0x70);
                local_d0 = 0x5c;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                pcVar13 = *(code **)(param_1 + 0x68);
                goto LAB_23aaa368a;
              }
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
LAB_23aaa3ad3:
              lVar7 = FUN_23ebc0cf0();
              if (lVar7 == 0) goto LAB_23aaa4f39;
              plVar11 = (longlong *)FUN_23e8bc2f0(lVar7,DAT_23ed8fbb0);
              plVar8 = _DAT_23ed8fc20;
              if (plVar11 != (longlong *)0x0) {
                lVar7 = *(longlong *)(param_1 + 0x10);
                plVar10 = *(longlong **)(lVar7 + 0xe20);
                if (plVar10 == (longlong *)0x0) {
                  plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                }
                else {
                  lVar18 = plVar10[3];
                  *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
                  *(longlong *)(lVar7 + 0xe20) = lVar18;
                  *plVar10 = 1;
                }
                plVar10[4] = 0;
                lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(local_d8 + 0x1f8) + 0x10) + 0x2e8)
                ;
                lVar18 = plVar10[-1];
                puVar2 = *(undefined8 **)(lVar7 + 8);
                *puVar2 = plVar10 + -2;
                plVar10[-2] = lVar7;
                plVar10[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
                *(longlong **)(lVar7 + 8) = plVar10 + -2;
                lVar7 = DAT_23ed6a210;
                *plVar8 = *plVar8 + 1;
                plVar10[3] = (longlong)plVar8;
                if ((lVar7 == 0) &&
                   (lVar7 = PyImport_ImportModule(&DAT_23ec31700), DAT_23ed6a210 = lVar7, lVar7 == 0
                   )) {
                  DAT_23ed6a210 = 0;
                  goto LAB_23aaa33db;
                }
                plVar8 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23ed8fb78);
                pcVar17 = DAT_23ed6cd28;
                if (plVar8 != (longlong *)0x0) {
                  plVar12 = plVar9;
                  if (DAT_23ed6a4c0 == (longlong *)0x0) {
                    plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    if (plVar14 == (longlong *)0x0) goto LAB_23aaa4f26;
                    *plVar14 = *plVar14 + 1;
                    DAT_23ed6a4c0 = plVar14;
                  }
                  pcStack_a0 = pcVar17;
                  local_a8 = plVar8;
                  lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_a8);
                  *plVar8 = *plVar8 + -1;
                  if (*plVar8 == 0) {
                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                  }
                  if (lVar7 == 0) goto LAB_23aaa4aa0;
                  plVar10[4] = lVar7;
                  plVar8 = (longlong *)(*local_c0)(DAT_23ed6cd28,plVar10);
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  if (plVar8 == (longlong *)0x0) {
                    plVar8 = *(longlong **)(param_1 + 0x60);
                    pcVar16 = *(code **)(param_1 + 0x68);
                    local_c8 = *(code **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                      goto joined_r0x00023aaa510a;
                    }
                    goto LAB_23aaa4d00;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0x62;
                  plVar10 = (longlong *)FUN_23e914090(param_1,plVar11);
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  *plVar8 = *plVar8 + -1;
                  if (*plVar8 == 0) {
                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                  }
                  if (plVar10 == (longlong *)0x0) {
                    local_c8 = *(code **)(param_1 + 0x70);
                    plVar8 = *(longlong **)(param_1 + 0x60);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    pcVar16 = *(code **)(param_1 + 0x68);
                    goto joined_r0x00023aaa510a;
                  }
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  lVar7 = FUN_23ebc0cf0();
                  if (lVar7 == 0) {
                    FUN_23e915740(param_1,&local_78,DAT_23ed8fba8);
                    plVar8 = local_78;
                    pcVar16 = pcStack_70;
joined_r0x00023aaa5096:
                    if (local_68 != (code *)0x0) {
                      iVar5 = 99;
                      plVar10 = *(longlong **)(local_68 + 0x18);
                      local_c8 = local_68;
                      goto joined_r0x00023aaa44c6;
                    }
LAB_23aaa5031:
                    iVar5 = 99;
                    goto LAB_23aaa40f0;
                  }
                  plVar11 = (longlong *)FUN_23e8bc2f0(lVar7,DAT_23ed8fbb0);
                  plVar8 = _DAT_23ed8fc28;
                  if (plVar11 == (longlong *)0x0) {
                    local_c8 = *(code **)(param_1 + 0x70);
                    plVar8 = *(longlong **)(param_1 + 0x60);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pcVar16 = *(code **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
joined_r0x00023aaa502b:
                    if (local_c8 != (code *)0x0) {
LAB_23aaa4e5a:
                      iVar5 = 99;
                      goto LAB_23aaa4e60;
                    }
                    goto LAB_23aaa5031;
                  }
                  lVar7 = *(longlong *)(param_1 + 0x10);
                  plVar10 = *(longlong **)(lVar7 + 0xe20);
                  if (plVar10 == (longlong *)0x0) {
                    plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                  }
                  else {
                    lVar18 = plVar10[3];
                    *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
                    *(longlong *)(lVar7 + 0xe20) = lVar18;
                    *plVar10 = 1;
                  }
                  plVar10[4] = 0;
                  lVar7 = *(longlong *)
                           (*(longlong *)(*(longlong *)(local_d8 + 0x1f8) + 0x10) + 0x2e8);
                  lVar18 = plVar10[-1];
                  puVar2 = *(undefined8 **)(lVar7 + 8);
                  *puVar2 = plVar10 + -2;
                  plVar10[-2] = lVar7;
                  plVar10[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
                  *(longlong **)(lVar7 + 8) = plVar10 + -2;
                  lVar7 = DAT_23ed6a210;
                  *plVar8 = *plVar8 + 1;
                  plVar10[3] = (longlong)plVar8;
                  if ((lVar7 == 0) &&
                     (lVar7 = PyImport_ImportModule(&DAT_23ec31700), DAT_23ed6a210 = lVar7,
                     lVar7 == 0)) {
                    DAT_23ed6a210 = 0;
                    goto LAB_23aaa33db;
                  }
                  plVar8 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23ed8fc10);
                  if (plVar8 == (longlong *)0x0) {
LAB_23aaa4dfd:
                    plVar8 = *(longlong **)(param_1 + 0x60);
                    pcVar16 = *(code **)(param_1 + 0x68);
                    local_c8 = *(code **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 != 0) {
                      iVar5 = 99;
                      goto joined_r0x00023aaa5001;
                    }
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                    goto joined_r0x00023aaa502b;
                  }
                  plVar14 = (longlong *)FUN_23a388650(param_1,plVar8,DAT_23ed6ccf0,0);
                  *plVar8 = *plVar8 + -1;
                  if (*plVar8 == 0) {
                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                  }
                  pcVar17 = DAT_23ed6cd28;
                  if (plVar14 == (longlong *)0x0) goto LAB_23aaa4dfd;
                  if (DAT_23ed6a4c0 == (longlong *)0x0) {
                    plVar8 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    if (plVar8 == (longlong *)0x0) goto LAB_23aaa4f26;
                    *plVar8 = *plVar8 + 1;
                    DAT_23ed6a4c0 = plVar8;
                  }
                  pcStack_a0 = pcVar17;
                  local_a8 = plVar14;
                  lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_a8);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  if (lVar7 == 0) goto LAB_23aaa4dfd;
                  plVar10[4] = lVar7;
                  plVar8 = (longlong *)(*local_c0)(DAT_23ed6cd28,plVar10);
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  if (plVar8 == (longlong *)0x0) {
                    plVar8 = *(longlong **)(param_1 + 0x60);
                    pcVar16 = *(code **)(param_1 + 0x68);
                    local_c8 = *(code **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 != 0) {
                      iVar5 = 99;
joined_r0x00023aaa529e:
                      if (local_c8 != (code *)0x0) goto LAB_23aaa4e60;
                      goto LAB_23aaa40f0;
                    }
                    FUN_23a334bc0(plVar11);
                    if (local_c8 == (code *)0x0) goto LAB_23aaa5031;
                    goto LAB_23aaa4e5a;
                  }
                  *(undefined4 *)(plVar3 + 5) = 99;
                  plVar10 = (longlong *)FUN_23e914090(param_1,plVar11);
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))();
                  }
                  *plVar8 = *plVar8 + -1;
                  if (*plVar8 == 0) {
                    (**(code **)(plVar8[1] + 0x30))();
                  }
                  if (plVar10 == (longlong *)0x0) {
                    local_68 = *(code **)(param_1 + 0x70);
                    plVar8 = *(longlong **)(param_1 + 0x60);
                    pcVar16 = *(code **)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto joined_r0x00023aaa5096;
                  }
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  lVar7 = FUN_23ebc0cf0();
                  if (lVar7 == 0) {
                    FUN_23e915740(param_1,&local_78,DAT_23ed8fba8);
                    plVar8 = local_78;
                    pcVar16 = pcStack_70;
                    local_c8 = local_68;
joined_r0x00023aaa52db:
                    if (local_c8 != (code *)0x0) {
                      iVar5 = 100;
                      plVar10 = *(longlong **)(local_c8 + 0x18);
                      goto joined_r0x00023aaa44c6;
                    }
LAB_23aaa51d4:
                    iVar5 = 100;
                    goto LAB_23aaa40f0;
                  }
                  plVar11 = (longlong *)FUN_23e8bc2f0(lVar7,DAT_23ed8fbb0);
                  plVar8 = _DAT_23ed8fc30;
                  if (plVar11 == (longlong *)0x0) {
LAB_23aaa51b3:
                    local_c8 = *(code **)(param_1 + 0x70);
                    plVar8 = *(longlong **)(param_1 + 0x60);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pcVar16 = *(code **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
joined_r0x00023aaa51d2:
                    if (local_c8 != (code *)0x0) {
                      iVar5 = 100;
                      plVar10 = *(longlong **)(local_c8 + 0x18);
                      goto joined_r0x00023aaa44c6;
                    }
                    goto LAB_23aaa51d4;
                  }
                  lVar7 = *(longlong *)(param_1 + 0x10);
                  plVar10 = *(longlong **)(lVar7 + 0xe20);
                  if (plVar10 == (longlong *)0x0) {
                    plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                  }
                  else {
                    lVar18 = plVar10[3];
                    *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
                    *(longlong *)(lVar7 + 0xe20) = lVar18;
                    *plVar10 = 1;
                  }
                  plVar10[4] = 0;
                  lVar7 = *(longlong *)
                           (*(longlong *)(*(longlong *)(local_d8 + 0x1f8) + 0x10) + 0x2e8);
                  lVar18 = plVar10[-1];
                  puVar2 = *(undefined8 **)(lVar7 + 8);
                  *puVar2 = plVar10 + -2;
                  plVar10[-2] = lVar7;
                  plVar10[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
                  *(longlong **)(lVar7 + 8) = plVar10 + -2;
                  lVar7 = DAT_23ed6a210;
                  *plVar8 = *plVar8 + 1;
                  plVar10[3] = (longlong)plVar8;
                  if ((lVar7 == 0) &&
                     (lVar7 = PyImport_ImportModule(&DAT_23ec31700), DAT_23ed6a210 = lVar7,
                     lVar7 == 0)) {
                    DAT_23ed6a210 = 0;
LAB_23aaa33db:
                    FUN_23e9364c0("%s : %s\n","IMPORT_HARD_SYS",
                                  "\"Unexpected failure of hard import of \'sys\'\"");
                    /* WARNING: Subroutine does not return */
                    abort();
                  }
                  plVar8 = (longlong *)FUN_23e8bbbe0(param_1,lVar7,_DAT_23ed8fb88,pcVar16);
                  pcVar16 = DAT_23ed6cd28;
                  if (plVar8 == (longlong *)0x0) {
LAB_23aaa5115:
                    plVar8 = *(longlong **)(param_1 + 0x60);
                    pcVar16 = *(code **)(param_1 + 0x68);
                    local_c8 = *(code **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    lVar7 = *plVar11;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *plVar11 = lVar7 + -1;
                    if (lVar7 + -1 == 0) {
                      (**(code **)(plVar11[1] + 0x30))();
                    }
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 != 0) {
                      iVar5 = 100;
                      goto joined_r0x00023aaa529e;
                    }
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                    goto joined_r0x00023aaa51d2;
                  }
                  if (DAT_23ed6a4c0 == (longlong *)0x0) {
                    plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    if (plVar14 == (longlong *)0x0) goto LAB_23aaa4f26;
                    *plVar14 = *plVar14 + 1;
                    DAT_23ed6a4c0 = plVar14;
                  }
                  pcStack_a0 = pcVar16;
                  local_a8 = plVar8;
                  lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_a8);
                  *plVar8 = *plVar8 + -1;
                  if (*plVar8 == 0) {
                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                  }
                  if (lVar7 == 0) goto LAB_23aaa5115;
                  plVar10[4] = lVar7;
                  plVar8 = (longlong *)(*local_c0)(DAT_23ed6cd28,plVar10);
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  if (plVar8 != (longlong *)0x0) {
                    *(undefined4 *)(plVar3 + 5) = 100;
                    plVar10 = (longlong *)FUN_23e914090(param_1,plVar11,plVar8);
                    lVar7 = *plVar11;
                    *plVar11 = lVar7 + -1;
                    if (lVar7 + -1 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    if (plVar10 != (longlong *)0x0) {
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                      }
LAB_23aaa3008:
                      lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                      plVar8 = *(longlong **)(lVar7 + 0x28);
                      plVar3 = (longlong *)plVar8[2];
                      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                           *(undefined8 *)(lVar7 + 0x30);
                      *(undefined4 *)(plVar8 + 8) = 0xffffffff;
                      if (plVar3 != (longlong *)0x0) {
                        plVar8[2] = 0;
                        *plVar3 = *plVar3 + -1;
                        if (*plVar3 == 0) {
                          (**(code **)(plVar3[1] + 0x30))();
                        }
                      }
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 == 0) {
                        (**(code **)(plVar8[1] + 0x30))(plVar8);
                      }
                      plVar8[0xf] = 0;
                      *plVar9 = *plVar9 + 1;
                      *(longlong *)pcVar6 = *(longlong *)pcVar6 + -1;
                      if (*(longlong *)pcVar6 == 0) {
                        (**(code **)(*(longlong *)(pcVar6 + 8) + 0x30))(pcVar6);
                      }
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 != 0) {
                        return plVar9;
                      }
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                      return plVar9;
                    }
                    goto LAB_23aaa51b3;
                  }
                  local_c8 = *(code **)(param_1 + 0x70);
                  plVar8 = *(longlong **)(param_1 + 0x60);
                  pcVar16 = *(code **)(param_1 + 0x68);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  lVar7 = *plVar11;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar11 = lVar7 + -1;
                  if (lVar7 + -1 == 0) {
                    FUN_23a334bc0();
                    goto joined_r0x00023aaa52db;
                  }
                  iVar5 = 100;
joined_r0x00023aaa4d09:
                  if (local_c8 == (code *)0x0) goto LAB_23aaa40f0;
                  goto LAB_23aaa4587;
                }
LAB_23aaa4aa0:
                plVar8 = *(longlong **)(param_1 + 0x60);
                pcVar16 = *(code **)(param_1 + 0x68);
                local_c8 = *(code **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                *plVar10 = *plVar10 + -1;
                if (*plVar10 != 0) {
LAB_23aaa4d00:
                  iVar5 = 0x62;
                  goto joined_r0x00023aaa4d09;
                }
                (**(code **)(plVar10[1] + 0x30))(plVar10);
                goto joined_r0x00023aaa510a;
              }
              local_c8 = *(code **)(param_1 + 0x70);
              plVar8 = *(longlong **)(param_1 + 0x60);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar16 = *(code **)(param_1 + 0x68);
              iVar5 = 0x62;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (local_c8 != (code *)0x0) {
LAB_23aaa4587:
                plVar10 = *(longlong **)(local_c8 + 0x18);
                goto joined_r0x00023aaa44c6;
              }
            }
            iVar5 = 0x62;
            goto LAB_23aaa40f0;
          }
          iVar5 = *(int *)(lVar7 + 0xc);
          if (*(int *)(lVar7 + 0xc) == 0) {
            *(int *)(lVar7 + 0xc) = DAT_23ec107d0;
            iVar5 = DAT_23ec107d0;
            DAT_23ec107d0 = DAT_23ec107d0 + 1;
          }
          if (_DAT_23ec107cc != iVar5) {
            _DAT_23ec107cc = iVar5;
            _DAT_23ed90ce0 =
                 FUN_23e8cbd60(lVar7,DAT_23ed6cdd0,*(undefined8 *)(DAT_23ed6cdd0 + 0x18));
          }
          if (-1 < _DAT_23ed90ce0) {
            lVar1 = lVar7 + 0x20 + (1L << (*(byte *)(lVar7 + 9) & 0x3f));
            lVar18 = *(longlong *)(lVar1 + 8 + _DAT_23ed90ce0 * 0x10);
            if (lVar18 != 0) goto LAB_23aaa310d;
            _DAT_23ed90ce0 =
                 FUN_23e8cbd60(lVar7,DAT_23ed6cdd0,*(undefined8 *)(DAT_23ed6cdd0 + 0x18));
            if (-1 < _DAT_23ed90ce0) {
              lVar18 = *(longlong *)(lVar1 + 8 + _DAT_23ed90ce0 * 0x10);
              goto LAB_23aaa46f8;
            }
          }
LAB_23aaa3348:
          plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ed6cdd0);
          if ((plVar8 != (longlong *)0x0) && (lVar18 = *plVar8, lVar18 != 0)) goto LAB_23aaa310d;
          plVar11 = (longlong *)0x0;
          FUN_23e915740(param_1,&local_78,DAT_23ed6cdd0);
          local_d0 = 0x5b;
          local_d8 = _PyRuntime_exref;
          pcVar17 = local_68;
          plVar8 = local_78;
          pcVar13 = pcStack_70;
LAB_23aaa368a:
          plVar10 = *(longlong **)(param_1 + 0x138);
          local_98._8_8_ = pcVar13;
          local_98._0_8_ = plVar8;
          if (plVar10 != (longlong *)0x0) {
            *plVar10 = *plVar10 + 1;
          }
          pcVar13 = DAT_23ed6a4f8;
          local_88[0] = pcVar17;
          if (pcVar17 == (code *)0x0) {
            if (DAT_23ed6a4f8 == (code *)0x0) {
              pcVar13 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
            }
            else {
              pcVar17 = *(code **)DAT_23ed6a4f8;
              *(undefined8 *)DAT_23ed6a4f8 = 1;
              DAT_23ed6a4f8 = pcVar17;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            }
            *(longlong **)(pcVar13 + 0x18) = plVar3;
            *(longlong *)(pcVar13 + 0x10) = 0;
            *plVar3 = *plVar3 + 1;
            lVar7 = *(longlong *)(local_d8 + 0x1f8);
            *(undefined4 *)(pcVar13 + 0x24) = local_d0;
            *(undefined4 *)(pcVar13 + 0x20) = 0xffffffff;
            lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
            lVar18 = *(longlong *)(pcVar13 + -8);
            plVar8 = *(longlong **)(lVar7 + 8);
            *plVar8 = (longlong)(pcVar13 + -0x10);
            *(longlong *)(pcVar13 + -0x10) = lVar7;
            *(ulonglong *)(pcVar13 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)plVar8;
            *(code **)(lVar7 + 8) = pcVar13 + -0x10;
            if ((local_88[0] != (code *)0x0) &&
               (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1,
               *(longlong *)local_88[0] == 0)) {
              (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))(local_88[0]);
            }
          }
          else {
            if (DAT_23ed6a4f8 == (code *)0x0) {
              pcVar13 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
            }
            else {
              pcVar4 = *(code **)DAT_23ed6a4f8;
              *(undefined8 *)DAT_23ed6a4f8 = 1;
              DAT_23ed6a4f8 = pcVar4;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            }
            *(longlong **)(pcVar13 + 0x18) = plVar3;
            *plVar3 = *plVar3 + 1;
            lVar7 = *(longlong *)(local_d8 + 0x1f8);
            *(undefined4 *)(pcVar13 + 0x24) = local_d0;
            *(undefined4 *)(pcVar13 + 0x20) = 0xffffffff;
            lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
            lVar18 = *(longlong *)(pcVar13 + -8);
            plVar8 = *(longlong **)(lVar7 + 8);
            *plVar8 = (longlong)(pcVar13 + -0x10);
            *(longlong *)(pcVar13 + -0x10) = lVar7;
            *(ulonglong *)(pcVar13 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)plVar8;
            *(code **)(lVar7 + 8) = pcVar13 + -0x10;
            *(code **)(pcVar13 + 0x10) = pcVar17;
            *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
            if ((local_88[0] != (code *)0x0) &&
               (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1,
               *(longlong *)local_88[0] == 0)) {
              (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
            }
          }
          pcVar4 = _Py_NoneStruct_exref;
          local_88[0] = pcVar13;
          if (((code *)local_98._0_8_ != _Py_NoneStruct_exref) &&
             ((code *)local_98._0_8_ != (code *)0x0)) {
            FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
          }
          plVar8 = *(longlong **)(local_98._8_8_ + 0x28);
          if (local_88[0] == pcVar4) {
            pcVar17 = (code *)0x0;
          }
          else {
            pcVar17 = local_88[0];
            if (local_88[0] != (code *)0x0) {
              *(longlong *)local_88[0] = *(longlong *)local_88[0] + 1;
            }
          }
          *(code **)(local_98._8_8_ + 0x28) = pcVar17;
          if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
            (**(code **)(plVar8[1] + 0x30))();
          }
          plVar8 = *(longlong **)(param_1 + 0x138);
          *(undefined8 *)(param_1 + 0x138) = local_98._8_8_;
          if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
            (**(code **)(plVar8[1] + 0x30))();
          }
          *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + -1;
          if (*(longlong *)local_98._0_8_ == 0) {
            (**(code **)(*(longlong *)(local_98._0_8_ + 8) + 0x30))();
          }
          if ((local_88[0] != (code *)0x0) &&
             (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1,
             *(longlong *)local_88[0] == 0)) {
            (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
          }
          local_88[0] = (code *)0x0;
          local_98 = (undefined1  [16])0x0;
          iVar5 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                _DAT_23ed8fc08);
          plVar9 = plVar11;
          if (iVar5 != -1) {
            if (iVar5 == 0) {
              pcVar17 = *(code **)(param_1 + 0x138);
              if ((pcVar17 == pcVar4) || (pcVar17 == (code *)0x0)) {
                plVar8 = *(longlong **)PyExc_RuntimeError_exref;
                pcVar16 = (code *)PyUnicode_FromString("No active exception to reraise");
                pcVar17 = *(code **)(param_1 + 0x138);
                iVar5 = 0x5a;
                *plVar8 = *plVar8 + 1;
                *(longlong **)(param_1 + 0x138) = plVar10;
                if ((pcVar17 == (code *)0x0) ||
                   (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 != 0))
                goto LAB_23aaa40f0;
LAB_23aaa4551:
                (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
                goto LAB_23aaa4562;
              }
              plVar8 = *(longlong **)(pcVar17 + 8);
              local_c8 = *(code **)(pcVar17 + 0x28);
              *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
              *plVar8 = *plVar8 + 1;
              pcVar16 = pcVar17;
              if (local_c8 != (code *)0x0) {
                *(longlong *)local_c8 = *(longlong *)local_c8 + 1;
                if (plVar3 == *(longlong **)(local_c8 + 0x18)) {
                  *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(local_c8 + 0x24);
                }
                *(longlong **)(param_1 + 0x138) = plVar10;
                *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
                if (*(longlong *)pcVar17 == 0) {
                  (*(code *)plVar8[6])(pcVar17);
                  iVar5 = 0;
                  goto LAB_23aaa4377;
                }
                pcVar13 = local_c8;
                if (*(longlong **)(local_c8 + 0x18) == plVar3) goto LAB_23aaa34f0;
                goto LAB_23aaa42b0;
              }
              *(longlong **)(param_1 + 0x138) = plVar10;
              *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
              if (*(longlong *)pcVar17 == 0) {
                iVar5 = 0;
                goto LAB_23aaa4551;
              }
LAB_23aaa456b:
              iVar5 = (int)plVar3[5];
              plVar9 = plVar11;
            }
            else {
              if ((DAT_23ed6a210 == 0) &&
                 (DAT_23ed6a210 = PyImport_ImportModule(&DAT_23ec31700), DAT_23ed6a210 == 0)) {
                DAT_23ed6a210 = 0;
                goto LAB_23aaa33db;
              }
              plVar8 = (longlong *)FUN_23e8bc2f0(DAT_23ed6a210,_DAT_23ed8fc10);
              if (plVar8 == (longlong *)0x0) {
LAB_23aaa4310:
                plVar14 = *(longlong **)(param_1 + 0x138);
                plVar8 = *(longlong **)(param_1 + 0x60);
                *(longlong **)(param_1 + 0x138) = plVar10;
                pcVar16 = *(code **)(param_1 + 0x68);
                local_c8 = *(code **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                if (plVar14 != (longlong *)0x0) {
LAB_23aaa4343:
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    iVar5 = 0x5f;
                    goto LAB_23aaa4353;
                  }
                }
                if (local_c8 != (code *)0x0) {
                  iVar5 = 0x5f;
                  goto LAB_23aaa44c2;
                }
              }
              else {
                plVar9 = (longlong *)FUN_23a388650(param_1,plVar8,DAT_23ed6ccf0,0);
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                if (plVar9 != (longlong *)0x0) {
                  plVar8 = (longlong *)FUN_23e937070(param_1);
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  if (plVar8 != (longlong *)0x0) {
                    plVar9 = (longlong *)FUN_23e936ef0(param_1,plVar8);
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    if (plVar9 != (longlong *)0x0) {
                      if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0))
                      {
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                      }
                      lVar7 = FUN_23ebc0cf0();
                      if (lVar7 == 0) {
                        FUN_23e915740(param_1,&local_78,DAT_23ed8fba8);
                        plVar14 = *(longlong **)(param_1 + 0x138);
                        *(longlong **)(param_1 + 0x138) = plVar10;
                        plVar8 = local_78;
                        pcVar16 = pcStack_70;
                        local_c8 = local_68;
                      }
                      else {
                        plVar11 = (longlong *)FUN_23e8bc2f0(lVar7,DAT_23ed8fbb0);
                        plVar8 = _DAT_23ed8fc18;
                        if (plVar11 == (longlong *)0x0) {
LAB_23aaa4930:
                          local_c8 = *(code **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          plVar8 = *(longlong **)(param_1 + 0x60);
                          pcVar16 = *(code **)(param_1 + 0x68);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23aaa494c:
                          plVar14 = *(longlong **)(param_1 + 0x138);
                          *(longlong **)(param_1 + 0x138) = plVar10;
                        }
                        else {
                          lVar7 = *(longlong *)(param_1 + 0x10);
                          plVar12 = *(longlong **)(lVar7 + 0xe20);
                          if (plVar12 == (longlong *)0x0) {
                            plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                          }
                          else {
                            lVar18 = plVar12[3];
                            *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
                            *(longlong *)(lVar7 + 0xe20) = lVar18;
                            *plVar12 = 1;
                          }
                          plVar12[4] = 0;
                          lVar7 = *(longlong *)
                                   (*(longlong *)(*(longlong *)(local_d8 + 0x1f8) + 0x10) + 0x2e8);
                          lVar18 = plVar12[-1];
                          puVar2 = *(undefined8 **)(lVar7 + 8);
                          *puVar2 = plVar12 + -2;
                          plVar12[-2] = lVar7;
                          plVar12[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
                          *(longlong **)(lVar7 + 8) = plVar12 + -2;
                          plVar14 = DAT_23ed6a4c0;
                          *plVar8 = *plVar8 + 1;
                          plVar12[3] = (longlong)plVar8;
                          pcVar17 = DAT_23ed6cd28;
                          if (plVar14 == (longlong *)0x0) {
                            plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                            if (plVar14 == (longlong *)0x0) goto LAB_23aaa4f26;
                            *plVar14 = *plVar14 + 1;
                            DAT_23ed6a4c0 = plVar14;
                          }
                          pcStack_a0 = pcVar17;
                          local_a8 = plVar9;
                          lVar7 = FUN_23e94ed00(param_1,plVar14,&local_a8);
                          if (lVar7 == 0) {
                            plVar8 = *(longlong **)(param_1 + 0x60);
                            pcVar16 = *(code **)(param_1 + 0x68);
                            local_c8 = *(code **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *plVar11 = *plVar11 + -1;
                            if (*plVar11 == 0) {
                              (**(code **)(plVar11[1] + 0x30))(plVar11);
                            }
                            *plVar12 = *plVar12 + -1;
                            if (*plVar12 != 0) goto LAB_23aaa494c;
                            lVar7 = plVar12[1];
                          }
                          else {
                            plVar12[4] = lVar7;
                            local_c0 = PyUnicode_Join_exref;
                            plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
                            *plVar12 = *plVar12 + -1;
                            if (*plVar12 == 0) {
                              (**(code **)(plVar12[1] + 0x30))(plVar12);
                            }
                            if (plVar8 != (longlong *)0x0) {
                              *(undefined4 *)(plVar3 + 5) = 0x60;
                              plVar14 = (longlong *)FUN_23e914090(param_1,plVar11);
                              *plVar11 = *plVar11 + -1;
                              if (*plVar11 == 0) {
                                (**(code **)(plVar11[1] + 0x30))(plVar11);
                              }
                              *plVar8 = *plVar8 + -1;
                              if (*plVar8 == 0) {
                                (**(code **)(plVar8[1] + 0x30))(plVar8);
                              }
                              if (plVar14 != (longlong *)0x0) {
                                *plVar14 = *plVar14 + -1;
                                if (*plVar14 == 0) {
                                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                                }
                                plVar8 = *(longlong **)(param_1 + 0x138);
                                *(longlong **)(param_1 + 0x138) = plVar10;
                                if ((plVar8 != (longlong *)0x0) &&
                                   (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
                                  (**(code **)(plVar8[1] + 0x30))();
                                }
                                goto LAB_23aaa3ad3;
                              }
                              goto LAB_23aaa4930;
                            }
                            plVar8 = *(longlong **)(param_1 + 0x60);
                            pcVar16 = *(code **)(param_1 + 0x68);
                            local_c8 = *(code **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *plVar11 = *plVar11 + -1;
                            if (*plVar11 != 0) goto LAB_23aaa494c;
                            lVar7 = plVar11[1];
                            plVar12 = plVar11;
                          }
                          (**(code **)(lVar7 + 0x30))(plVar12);
                          plVar14 = *(longlong **)(param_1 + 0x138);
                          *(longlong **)(param_1 + 0x138) = plVar10;
                        }
                      }
                      plVar11 = plVar9;
                      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0))
                      {
                        iVar5 = 0x60;
                        goto LAB_23aaa4353;
                      }
                      if (local_c8 == (code *)0x0) {
                        iVar5 = 0x60;
                        goto LAB_23aaa40f0;
                      }
                      iVar5 = 0x60;
                      goto LAB_23aaa44c2;
                    }
                  }
                  goto LAB_23aaa4310;
                }
                plVar14 = *(longlong **)(param_1 + 0x138);
                plVar8 = *(longlong **)(param_1 + 0x60);
                *(longlong **)(param_1 + 0x138) = plVar10;
                pcVar16 = *(code **)(param_1 + 0x68);
                local_c8 = *(code **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                if (plVar14 != (longlong *)0x0) goto LAB_23aaa4343;
                iVar5 = 0x5f;
                if (local_c8 != (code *)0x0) goto LAB_23aaa44c2;
              }
              iVar5 = 0x5f;
              plVar9 = plVar11;
            }
            goto LAB_23aaa40f0;
          }
          plVar14 = *(longlong **)(param_1 + 0x138);
          plVar8 = *(longlong **)(param_1 + 0x60);
          *(longlong **)(param_1 + 0x138) = plVar10;
          pcVar16 = *(code **)(param_1 + 0x68);
          local_c8 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          if (plVar14 == (longlong *)0x0) {
            iVar5 = 0x5d;
            if (local_c8 == (code *)0x0) {
LAB_23aaa4ec8:
              iVar5 = 0x5d;
              goto LAB_23aaa40f0;
            }
          }
          else {
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              iVar5 = 0x5d;
LAB_23aaa4353:
              (**(code **)(plVar14[1] + 0x30))();
              if (local_c8 != (code *)0x0) {
LAB_23aaa4377:
                pcVar17 = pcVar16;
                pcVar13 = local_c8;
                if (plVar3 == *(longlong **)(local_c8 + 0x18)) goto LAB_23aaa34f0;
                if (iVar5 != 0) goto LAB_23aaa3450;
LAB_23aaa42b0:
                iVar5 = (int)plVar3[5];
                goto LAB_23aaa3450;
              }
LAB_23aaa4562:
              plVar9 = plVar11;
              if (iVar5 == 0) goto LAB_23aaa456b;
              goto LAB_23aaa40f0;
            }
            if (local_c8 == (code *)0x0) goto LAB_23aaa4ec8;
            iVar5 = 0x5d;
          }
LAB_23aaa44c2:
          plVar10 = *(longlong **)(local_c8 + 0x18);
          plVar9 = plVar11;
        }
joined_r0x00023aaa44c6:
        plVar11 = plVar9;
        pcVar17 = pcVar16;
        pcVar13 = local_c8;
        if (plVar10 == plVar3) goto LAB_23aaa34f0;
        goto LAB_23aaa3450;
      }
      local_c8 = *(code **)(param_1 + 0x70);
      plVar8 = *(longlong **)(param_1 + 0x60);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar16 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (local_c8 != (code *)0x0) {
        if (plVar3 == *(longlong **)(local_c8 + 0x18)) goto LAB_23aaa35ff;
        plVar11 = (longlong *)0x0;
        iVar5 = 0x57;
        local_d8 = _PyRuntime_exref;
        goto LAB_23aaa3450;
      }
      plVar9 = (longlong *)0x0;
      iVar5 = 0x57;
      local_d8 = _PyRuntime_exref;
    }
LAB_23aaa40f0:
    pcVar13 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar13 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar17 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar17;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong *)(pcVar13 + 0x10) = 0;
    *(longlong **)(pcVar13 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar7 = *(longlong *)(local_d8 + 0x1f8);
    *(int *)(pcVar13 + 0x24) = iVar5;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)(pcVar13 + 0x20) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar18 = *(longlong *)(pcVar13 + -8);
    plVar11 = *(longlong **)(lVar7 + 8);
    *plVar11 = (longlong)(pcVar13 + -0x10);
    *(longlong *)(pcVar13 + -0x10) = lVar7;
    *(ulonglong *)(pcVar13 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)plVar11;
    *(code **)(lVar7 + 8) = pcVar13 + -0x10;
    plVar11 = plVar9;
    pcVar17 = pcVar16;
  }
LAB_23aaa34f0:
  FUN_23e8bba40(plVar3,&DAT_23ec31937,pcVar6,plVar11);
  if (plVar3 == _DAT_23ed90cf0) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23ed90cf0 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar7 + 0x28);
  plVar9 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar9 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar3[0xf] = 0;
  if ((pcVar6 != (code *)0x0) &&
     (*(longlong *)pcVar6 = *(longlong *)pcVar6 + -1, *(longlong *)pcVar6 == 0)) {
    (**(code **)(*(longlong *)(pcVar6 + 8) + 0x30))(pcVar6);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  FUN_23a33aa70(param_1,plVar8,pcVar17,pcVar13);
  return (longlong *)0x0;
}
