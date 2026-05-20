/* ===== 23e801b80 workers.fishing.memory_reeling:MemoryReelingTracker.stop ===== */
/* ghidra_name=FUN_23e801b80 entry=23e801b80 size=2758 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e801b80(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  code *pcVar13;
  code *pcVar14;
  code *pcVar15;
  undefined4 uVar16;
  code *local_a8;
  undefined1 local_98 [16];
  code *local_88 [2];
  undefined8 local_78;
  undefined8 uStack_70;
  code *local_68;
  
  plVar9 = _DAT_23eede918;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eede918 == (longlong *)0x0) {
LAB_23e801bc2:
    _DAT_23eede918 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede948,DAT_23eedd0f8,8);
  }
  else {
    lVar11 = *_DAT_23eede918;
    if (1 < lVar11) {
      *_DAT_23eede918 = lVar11 + -1;
      goto LAB_23e801bc2;
    }
    if (_DAT_23eede918[2] != 0) {
      *_DAT_23eede918 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e801bc2;
    }
  }
  plVar3 = _DAT_23eede918;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eede918 + 9;
  lVar2 = *(longlong *)(lVar11 + 8);
  _DAT_23eede918[0xf] = lVar2;
  *(longlong **)(lVar11 + 8) = plVar9;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar5 = DAT_23eedd258;
  *(undefined4 *)(plVar3 + 8) = 0;
  *(undefined4 *)(plVar3 + 5) = 0x98;
  plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar1,uVar5);
  if (plVar9 == (longlong *)0x0) {
    pcVar13 = *(code **)(param_1 + 0x70);
    plVar9 = *(longlong **)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar14 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcVar13 == (code *)0x0) {
      local_a8 = _PyRuntime_exref;
      uVar16 = 0x98;
      goto LAB_23e802319;
    }
    if (*(longlong **)(pcVar13 + 0x18) == plVar3) goto LAB_23e801f63;
    uVar16 = 0x98;
    local_a8 = _PyRuntime_exref;
    pcVar15 = pcVar13;
  }
  else {
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedd138);
    if (plVar10 != (longlong *)0x0) {
      iVar8 = FUN_23a35f020(plVar10);
      lVar11 = *plVar10 + -1;
      if (iVar8 == -1) {
        plVar9 = *(longlong **)(param_1 + 0x60);
        pcVar14 = *(code **)(param_1 + 0x68);
        pcVar13 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar10 = lVar11;
        if (lVar11 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
          goto joined_r0x00023e80225f;
        }
        if (pcVar13 != (code *)0x0) goto LAB_23e802261;
        goto LAB_23e8022e0;
      }
      *plVar10 = lVar11;
      if (lVar11 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      pcVar13 = _Py_NoneStruct_exref;
      if (iVar8 == 0) {
LAB_23e801ccf:
        cVar7 = FUN_23e8d9ac0(plVar1,DAT_23eedd138,pcVar13);
        if (cVar7 != '\0') {
          lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar9 = *(longlong **)(lVar11 + 0x28);
          plVar3 = (longlong *)plVar9[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
          *(undefined4 *)(plVar9 + 8) = 0xffffffff;
          if (plVar3 != (longlong *)0x0) {
            plVar9[2] = 0;
            *plVar3 = *plVar3 + -1;
            if (*plVar3 == 0) {
              (**(code **)(plVar3[1] + 0x30))();
            }
          }
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
          plVar9[0xf] = 0;
          *plVar1 = *plVar1 + -1;
          if (*plVar1 != 0) {
            return pcVar13;
          }
          (**(code **)(plVar1[1] + 0x30))(plVar1);
          return pcVar13;
        }
        pcVar13 = *(code **)(param_1 + 0x70);
        plVar9 = *(longlong **)(param_1 + 0x60);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar14 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcVar13 != (code *)0x0) {
          if (*(longlong **)(pcVar13 + 0x18) == plVar3) goto LAB_23e801f63;
          uVar16 = 0x9e;
          local_a8 = _PyRuntime_exref;
          pcVar15 = pcVar13;
          goto LAB_23e801db8;
        }
        uVar16 = 0x9e;
        local_a8 = _PyRuntime_exref;
      }
      else {
        lVar11 = FUN_23e8dcc30();
        if (lVar11 == 0) {
          FUN_23e915740(param_1,&local_78,DAT_23eedd200);
          pcVar13 = local_68;
        }
        else {
          plVar9 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23eedd260);
          if (plVar9 != (longlong *)0x0) {
            plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedd138);
            if (plVar10 == (longlong *)0x0) {
              local_78 = *(undefined8 *)(param_1 + 0x60);
              uStack_70 = *(undefined8 *)(param_1 + 0x68);
              pcVar13 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              goto LAB_23e802029;
            }
            *(undefined4 *)(plVar3 + 5) = 0x9b;
            plVar12 = (longlong *)FUN_23e914090(param_1,plVar9,plVar10);
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            if (plVar12 != (longlong *)0x0) {
              *plVar12 = *plVar12 + -1;
              pcVar13 = _Py_NoneStruct_exref;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              goto LAB_23e801ccf;
            }
          }
          pcVar13 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          local_78 = *(undefined8 *)(param_1 + 0x60);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uStack_70 = *(undefined8 *)(param_1 + 0x68);
        }
LAB_23e802029:
        plVar10 = *(longlong **)(param_1 + 0x138);
        local_98._8_8_ = uStack_70;
        local_98._0_8_ = local_78;
        if (plVar10 != (longlong *)0x0) {
          *plVar10 = *plVar10 + 1;
        }
        pcVar14 = DAT_23ed6a4f8;
        local_88[0] = pcVar13;
        if (pcVar13 == (code *)0x0) {
          if (DAT_23ed6a4f8 == (code *)0x0) {
            pcVar14 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            pcVar13 = *(code **)DAT_23ed6a4f8;
            *(longlong *)DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = pcVar13;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          *(longlong **)(pcVar14 + 0x18) = plVar3;
          *(longlong *)(pcVar14 + 0x10) = 0;
          *plVar3 = *plVar3 + 1;
          *(longlong *)(pcVar14 + 0x20) = 0x9bffffffff;
          local_a8 = _PyRuntime_exref;
          lVar11 = *(longlong *)
                    (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
          lVar2 = *(longlong *)(pcVar14 + -8);
          puVar4 = *(undefined8 **)(lVar11 + 8);
          *puVar4 = pcVar14 + -0x10;
          *(longlong *)(pcVar14 + -0x10) = lVar11;
          *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
          *(code **)(lVar11 + 8) = pcVar14 + -0x10;
          if ((local_88[0] != (code *)0x0) &&
             (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1,
             *(longlong *)local_88[0] == 0)) {
            (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))(local_88[0]);
          }
        }
        else {
          if (DAT_23ed6a4f8 == (code *)0x0) {
            pcVar14 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            pcVar15 = *(code **)DAT_23ed6a4f8;
            *(longlong *)DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = pcVar15;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          *(longlong **)(pcVar14 + 0x18) = plVar3;
          *plVar3 = *plVar3 + 1;
          *(longlong *)(pcVar14 + 0x20) = 0x9bffffffff;
          local_a8 = _PyRuntime_exref;
          lVar11 = *(longlong *)
                    (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
          lVar2 = *(longlong *)(pcVar14 + -8);
          puVar4 = *(undefined8 **)(lVar11 + 8);
          *puVar4 = pcVar14 + -0x10;
          *(longlong *)(pcVar14 + -0x10) = lVar11;
          *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
          *(code **)(lVar11 + 8) = pcVar14 + -0x10;
          *(code **)(pcVar14 + 0x10) = pcVar13;
          *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
          if ((local_88[0] != (code *)0x0) &&
             (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1,
             *(longlong *)local_88[0] == 0)) {
            (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
          }
        }
        pcVar13 = _Py_NoneStruct_exref;
        local_88[0] = pcVar14;
        if (((code *)local_98._0_8_ != (code *)0x0) &&
           ((code *)local_98._0_8_ != _Py_NoneStruct_exref)) {
          FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
        }
        plVar9 = *(longlong **)(local_98._8_8_ + 0x28);
        if (local_88[0] == pcVar13) {
          pcVar14 = (code *)0x0;
        }
        else {
          pcVar14 = local_88[0];
          if (local_88[0] != (code *)0x0) {
            *(longlong *)local_88[0] = *(longlong *)local_88[0] + 1;
          }
        }
        *(code **)(local_98._8_8_ + 0x28) = pcVar14;
        if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
          (**(code **)(plVar9[1] + 0x30))();
        }
        plVar9 = *(longlong **)(param_1 + 0x138);
        *(undefined8 *)(param_1 + 0x138) = local_98._8_8_;
        if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
          (**(code **)(plVar9[1] + 0x30))();
        }
        *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + -1;
        if (*(longlong *)local_98._0_8_ == 0) {
          (**(code **)(*(longlong *)(local_98._0_8_ + 8) + 0x30))();
        }
        if ((local_88[0] != (code *)0x0) &&
           (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0)
           ) {
          (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
        }
        local_88[0] = (code *)0x0;
        local_98 = (undefined1  [16])0x0;
        iVar8 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                              *(undefined8 *)PyExc_Exception_exref);
        if (iVar8 != 0) {
          plVar9 = *(longlong **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = plVar10;
          if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
            (**(code **)(plVar9[1] + 0x30))();
          }
          goto LAB_23e801ccf;
        }
        pcVar14 = *(code **)(param_1 + 0x138);
        if ((pcVar14 == (code *)0x0) || (pcVar14 == pcVar13)) {
          plVar9 = *(longlong **)PyExc_RuntimeError_exref;
          pcVar14 = (code *)PyUnicode_FromString("No active exception to reraise");
          plVar12 = *(longlong **)(param_1 + 0x138);
          *plVar9 = *plVar9 + 1;
          *(longlong **)(param_1 + 0x138) = plVar10;
          if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
            (**(code **)(plVar12[1] + 0x30))();
          }
          uVar16 = 0x9a;
        }
        else {
          plVar9 = *(longlong **)(pcVar14 + 8);
          pcVar13 = *(code **)(pcVar14 + 0x28);
          *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
          *plVar9 = *plVar9 + 1;
          if (pcVar13 != (code *)0x0) {
            *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
            if (plVar3 == *(longlong **)(pcVar13 + 0x18)) {
              *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar13 + 0x24);
              *(longlong **)(param_1 + 0x138) = plVar10;
              *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
              if (*(longlong *)pcVar14 != 0) goto LAB_23e801f63;
LAB_23e8025dd:
              (*(code *)plVar9[6])(pcVar14);
              if (plVar3 == *(longlong **)(pcVar13 + 0x18)) goto LAB_23e801f63;
            }
            else {
              *(longlong **)(param_1 + 0x138) = plVar10;
              *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
              if (*(longlong *)pcVar14 == 0) goto LAB_23e8025dd;
            }
            uVar16 = (undefined4)plVar3[5];
            pcVar15 = pcVar13;
            goto LAB_23e801db8;
          }
          *(longlong **)(param_1 + 0x138) = plVar10;
          *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
          if (*(longlong *)pcVar14 == 0) {
            (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
          }
          uVar16 = (undefined4)plVar3[5];
        }
      }
LAB_23e802319:
      pcVar13 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar13 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar15 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar15;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong *)(pcVar13 + 0x10) = 0;
      *(longlong **)(pcVar13 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      lVar11 = *(longlong *)(local_a8 + 0x1f8);
      *(undefined4 *)(pcVar13 + 0x20) = 0xffffffff;
      lVar11 = *(longlong *)(lVar11 + 0x10);
      *(undefined4 *)(pcVar13 + 0x24) = uVar16;
      lVar11 = *(longlong *)(lVar11 + 0x2e8);
      lVar2 = *(longlong *)(pcVar13 + -8);
      puVar4 = *(undefined8 **)(lVar11 + 8);
      *puVar4 = pcVar13 + -0x10;
      *(longlong *)(pcVar13 + -0x10) = lVar11;
      *(ulonglong *)(pcVar13 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      *(code **)(lVar11 + 8) = pcVar13 + -0x10;
      goto LAB_23e801f63;
    }
    pcVar13 = *(code **)(param_1 + 0x70);
    plVar9 = *(longlong **)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar14 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
joined_r0x00023e80225f:
    if (pcVar13 == (code *)0x0) {
LAB_23e8022e0:
      uVar16 = 0x99;
      local_a8 = _PyRuntime_exref;
      goto LAB_23e802319;
    }
LAB_23e802261:
    if (*(longlong **)(pcVar13 + 0x18) == plVar3) goto LAB_23e801f63;
    local_a8 = _PyRuntime_exref;
    uVar16 = 0x99;
    pcVar15 = pcVar13;
  }
LAB_23e801db8:
  pcVar13 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar13 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar6 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar6;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong **)(pcVar13 + 0x18) = plVar3;
  *plVar3 = *plVar3 + 1;
  lVar11 = *(longlong *)(local_a8 + 0x1f8);
  *(undefined4 *)(pcVar13 + 0x20) = 0xffffffff;
  *(undefined4 *)(pcVar13 + 0x24) = uVar16;
  lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
  lVar2 = *(longlong *)(pcVar13 + -8);
  puVar4 = *(undefined8 **)(lVar11 + 8);
  *puVar4 = pcVar13 + -0x10;
  *(longlong *)(pcVar13 + -0x10) = lVar11;
  *(ulonglong *)(pcVar13 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
  lVar2 = *(longlong *)pcVar15;
  *(code **)(lVar11 + 8) = pcVar13 + -0x10;
  *(code **)(pcVar13 + 0x10) = pcVar15;
  if (lVar2 == 0) {
    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
  }
LAB_23e801f63:
  FUN_23e8bba40(plVar3,&DAT_23ec5e2bc,plVar1);
  if (_DAT_23eede918 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eede918 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar11 + 0x28);
  plVar10 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar10 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar3[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,plVar9,pcVar14,pcVar13);
  return (code *)0x0;
}
